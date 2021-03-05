#include <iostream>
#include <vector>

int main() {

  long long first_sequence_size, second_sequence_size;
  std::cin >> first_sequence_size >> second_sequence_size;

  std::vector<long long> first_sequence(first_sequence_size + 1);
  for (int i = 1; i <= first_sequence_size; ++i) {
    std::cin >> first_sequence[i];
  }

  std::vector<long long> second_sequence(second_sequence_size + 1);
  for (int i = 1; i <= second_sequence_size; ++i) {
    std::cin >> second_sequence[i];
  }

  std::vector<std::vector<long long>> dp(first_sequence_size + 1,
                                         std::vector<long long>(second_sequence_size + 1));

  for (int i = 1; i <= first_sequence_size; ++i) {
    long long best = 0;

    for (int j = 1; j <= second_sequence_size; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (first_sequence[i] == second_sequence[j] && dp[i - 1][j] < best + 1) {
        dp[i][j] = best + 1;
      }
      if (first_sequence[i] > second_sequence[j] && dp[i - 1][j] > best) {
        best = dp[i - 1][j];
      }
    }
  }

  long long max = -1;

  for (auto i : dp.back()) {
    max = std::max(max, i);
  }

  std::cout << max;

  return 0;
}
