#include <iostream>
#include <list>
#include <vector>

class HashTable {
 public:
  HashTable() : table_(TABLE_SIZE_) {}

  int Swap(size_t x, size_t y) {
    KeyAndValue<int, int>* x_pointer = GetPointerToElement(x);
    KeyAndValue<int, int>* y_pointer = GetPointerToElement(y);

    int result = abs(x_pointer->value_ - y_pointer->value_);
    std::swap(x_pointer->value_, y_pointer->value_);

    return result;
  }

 private:
  template <typename KeyType, typename ValueType>
  class KeyAndValue {
   public:
    KeyType key_;
    ValueType value_;

    KeyAndValue(KeyType key, ValueType value) : key_(key), value_(value) {}
  };

  static const size_t TABLE_SIZE_ = 999'979;
  std::vector<std::list<KeyAndValue<int, int>>> table_;

  static size_t hash_function_(size_t x) {
    return x % TABLE_SIZE_;
  }

  KeyAndValue<int, int>* GetPointerToElement(size_t number) {
    for (auto& i : table_[hash_function_(number)]) {
      if (i.key_ == number) {
        return &i;
      }
    }

    table_[hash_function_(number)].push_front(KeyAndValue<int, int>(number, number));
    return &table_[hash_function_(number)].front();
  }
};

int main() {
  int n;
  std::cin >> n;

  HashTable hash_table;
  size_t a, b;

  while (n-- > 0) {
    std::cin >> a >> b;
    std::cout << hash_table.Swap(a, b) << '\n';
  }

  return 0;
}
