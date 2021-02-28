#include <fstream>
#include <list>
#include <string>
#include <vector>

class HashTable {
 private:
  static const size_t TABLE_SIZE_ = 999'979;
  static const size_t PRIME_CONST_ = 31;

  std::vector<std::list<std::pair<std::string, std::string>>> table_;

  static size_t hash_function_(const std::string& str) {
    auto result = static_cast<size_t>(str[0]);

    for (int i = 1; i < str.size(); ++i) {
      result = ((result * PRIME_CONST_) % TABLE_SIZE_ + str[i]) % TABLE_SIZE_;
    }

    return result;
  }

 public:
  HashTable() : table_(TABLE_SIZE_) {}

  void Put(const std::string& x, std::string y) {
    size_t hash_of_x = hash_function_(x);
    for (auto& i : table_[hash_of_x]) {
      if (i.first == x) {
        i.second = y;
        return;
      }
    }

    table_[hash_function_(x)].push_front({x, y});
  }

  void Delete(const std::string& x) {
    size_t hash_of_x = hash_function_(x);
    for (auto i = table_[hash_of_x].begin(); i != table_[hash_of_x].end(); ++i) {
      if (i->first == x) {
        table_[hash_of_x].erase(i);
        return;
      }
    }
  }

  std::string Get(const std::string& x) {
    size_t hash_of_x = hash_function_(x);
    for (auto& i : table_[hash_of_x]) {
      if (i.first == x) {
        return i.second;
      }
    }

    return "none";
  }
};

int main() {
  std::ifstream in("map.in");
  std::ofstream out("map.out");

  HashTable hash_table;

  std::string command, x, y;

  while (in >> command >> x) {
    if (command == "put") {
      in >> y;
      hash_table.Put(x, y);
    } else if (command == "delete") {
      hash_table.Delete(x);
    } else {
      out << hash_table.Get(x) << std::endl;
    }
  }

  return 0;
}
