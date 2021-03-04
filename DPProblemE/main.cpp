#include <iostream>
#include <vector>

int main() {
  int size_of_first_sequence;
  std::cin >> size_of_first_sequence;
  std::vector<int> first_sequence(size_of_first_sequence);

  for (auto& i : first_sequence) {
    std::cin >> i;
  }

  int size_of_second_sequence;
  std::cin >> size_of_second_sequence;
  std::vector<int> second_sequence(size_of_second_sequence);

  for (auto& i : second_sequence) {
    std::cin >> i;
  }

  std::vector<std::vector<int>> answer_for_prefixes(size_of_first_sequence + 1,
                                                    std::vector<int>(size_of_second_sequence + 1));

  for (int i = 1; i <= size_of_first_sequence; ++i) {
    for (int j = 1; j <= size_of_second_sequence; ++j) {
      if (first_sequence[i - 1] == second_sequence[j - 1]) {
        answer_for_prefixes[i][j] = answer_for_prefixes[i - 1][j - 1] + 1;
      } else {
        answer_for_prefixes[i][j] = std::max(answer_for_prefixes[i - 1][j],
                                             answer_for_prefixes[i][j - 1]);
      }
    }
  }

  std::cout << answer_for_prefixes.back().back();

  return 0;
}