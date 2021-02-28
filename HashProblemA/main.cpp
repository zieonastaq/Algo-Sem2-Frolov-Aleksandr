#include <iostream>
#include <string>
#include <vector>

class HashTable {
 private:
  const long long M = 10000379;
  const long long a = 179;
  std::vector<std::vector<int>> table_of_values_;
  std::vector<std::vector<std::string>> tables_of_str_;

  long long Hash(const std::string& str) {
    long long result = str[0];

    for (int i = 1; i < str.size(); ++i) {
      result = ((result * a) % M + str[i]) % M;
    }

    return result;
  }

 public:
  HashTable() : table_of_values_(M), tables_of_str_(M) {}

  long long AddAndReturnValue(const std::string& str, long long value) {
    long long hash = Hash(str);

    for (int i = 0; i < tables_of_str_[hash].size(); ++i) {
      if (tables_of_str_[hash][i] == str) {
        table_of_values_[hash][i] += value;
        return table_of_values_[hash][i];
      }
    }

    table_of_values_[hash].push_back(value);
    tables_of_str_[hash].push_back(str);

    return value;
  }
};

int main() {
  HashTable table;
  std::string str;
  int value;

  while (std::cin >> str >> value) {
    std::cout << table.AddAndReturnValue(str, value) << '\n';
  }

  return 0;
}
