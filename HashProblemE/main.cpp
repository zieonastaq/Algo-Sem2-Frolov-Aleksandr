#include <fstream>
#include <list>
#include <string>
#include <utility>
#include <vector>

class HashTable {
 public:
  HashTable() : table_(TABLE_SIZE_) {}

  void Put(const std::string& x, const std::string& y) {
    size_t hash_of_x = hash_function_(x);
    for (auto& i : table_[hash_of_x]) {
      if (i.key_ == x) {
        i.value_ = y;
        return;
      }
    }

    table_[hash_function_(x)].push_front({x, y});
  }

  void Delete(const std::string& x) {
    size_t hash_of_x = hash_function_(x);
    for (auto i = table_[hash_of_x].begin(); i != table_[hash_of_x].end(); ++i) {
      if (i->key_ == x) {
        table_[hash_of_x].erase(i);
        return;
      }
    }
  }

  std::string Get(const std::string& x) {
    size_t hash_of_x = hash_function_(x);
    for (auto& i : table_[hash_of_x]) {
      if (i.key_ == x) {
        return i.value_;
      }
    }

    return "none";
  }

 private:
  template <typename KeyType, typename ValueType>
  class KeyAndValue {
   public:
    KeyType key_;
    ValueType value_;

    KeyAndValue(KeyType key, ValueType value) : key_(std::move(key)), value_(std::move(value)) {}
  };

  static const size_t TABLE_SIZE_ = 999'979;
  static const size_t PRIME_CONST_ = 31;

  std::vector<std::list<KeyAndValue<std::string, std::string>>> table_;

  static size_t hash_function_(const std::string& str) {
    auto result = static_cast<size_t>(str[0]);

    for (int i = 1; i < str.size(); ++i) {
      result = ((result * PRIME_CONST_) % TABLE_SIZE_ + str[i]) % TABLE_SIZE_;
    }

    return result;
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
