#include <iostream>
#include <list>
#include <vector>

class HashTable {
 private:
  static const size_t TABLE_SIZE_ = 999'979;
  std::vector<std::list<std::pair<int, int>>> table_;

  static size_t hash_function_(size_t x) {
    return x % TABLE_SIZE_;
  }

  std::pair<int, int>* GetPointerOfElement(size_t number) {
    for (auto& i : table_[hash_function_(number)]) {
      if (i.first == number) {
        return &i;
      }
    }

    table_[hash_function_(number)].push_front({number, number});
    return &table_[hash_function_(number)].front();
  }

 public:
  HashTable() : table_(TABLE_SIZE_) {}

  int Swap(size_t x, size_t y) {
    std::pair<int, int>* x_pointer = GetPointerOfElement(x);
    std::pair<int, int>* y_pointer = GetPointerOfElement(y);

    int result = abs(x_pointer->second - y_pointer->second);
    std::swap(x_pointer->second, y_pointer->second);

    return result;
  }
};

int main() {
  int n;
  std::cin >> n;

  HashTable hash_table;
  size_t a, b;

  while (n-->0) {
    std::cin >> a >> b;
    std::cout << hash_table.Swap(a, b) << '\n';
  }

  return 0;
}
