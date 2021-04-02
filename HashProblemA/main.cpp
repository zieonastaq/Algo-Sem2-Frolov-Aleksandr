#include <iostream>
#include <string>
#include <vector>

class HashTable {
 public:
  HashTable() : table_of_values_(M), table_of_strings_(M) {}

  long long AddAndReturnValue(const std::string& str, long long value) {
    long long hash = Hash(str);

    for (int i = 0; i < table_of_strings_[hash].size(); ++i) {
      if (table_of_strings_[hash][i] == str) {
        table_of_values_[hash][i] += value;
        return table_of_values_[hash][i];
      }
    }

    table_of_values_[hash].push_back(value);
    table_of_strings_[hash].push_back(str);

    return value;
  }

 private:
  const long long M = 10000379;
  const long long a = 179;
  std::vector<std::vector<int>> table_of_values_;
  std::vector<std::vector<std::string>> table_of_strings_;

  long long Hash(const std::string& str) {
    long long result = str[0];

    for (int i = 1; i < str.size(); ++i) {
      result = ((result * a) % M + str[i]) % M;
    }

    return result;
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
