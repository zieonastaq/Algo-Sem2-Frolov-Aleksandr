#include <algorithm>
#include <iostream>
#include <vector>

int main() {

  const int INF = INT32_MAX;

  int sequence_size;
  std::cin >> sequence_size;
  std::vector<int> sequence(sequence_size);

  for (auto& i : sequence) {
    std::cin >> i;
  }

  std::reverse(sequence.begin(), sequence.end());

  std::vector<int> dp(sequence_size + 1, INF);
  dp[0] = -INF;

  std::vector<int> position_of_optimal_ending(sequence_size + 1);
  position_of_optimal_ending[0] = -1;

  std::vector<int> position_of_previous_element(sequence_size);
  int length = 0;

  for (int i = 0; i < sequence_size; ++i) {
    int j = std::lower_bound(dp.begin(), dp.end(), sequence[i]) - dp.begin();

    if (dp[j - 1] <= sequence[i] && sequence[i] <= dp[j]) {
      dp[j] = sequence[i];
      position_of_optimal_ending[j] = i;
      position_of_previous_element[i] = position_of_optimal_ending[j - 1];
      length = std::max(length, j);
    }
  }

  std::vector<int> answer;
  int p = position_of_optimal_ending[length];

  while (p != -1) {
    answer.push_back(sequence_size - p);
    p = position_of_previous_element[p];
  }

  //std::reverse(answer.begin(), answer.end());

  std::cout << length << '\n';
  for (auto i : answer) {
    std::cout << i << ' ';
  }

  return 0;
}
