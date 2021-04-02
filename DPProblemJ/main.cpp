#include <iostream>
#include <vector>

int main() {

  int capacity, number_og_ingots;
  std::cin >> capacity >> number_og_ingots;

  std::vector<int> weights(number_og_ingots);
  for (auto& i : weights) {
    std::cin >> i;
  }

  std::vector<std::vector<int>> dp(number_og_ingots + 1, std::vector<int>(capacity + 1));

  for (int i = 1; i <= number_og_ingots; ++i) {
    for (int j = 1; j <= capacity; ++j) {
      if (j >= weights[i - 1]) {
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + weights[i - 1]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  std::cout << dp.back().back();

  return 0;
}
