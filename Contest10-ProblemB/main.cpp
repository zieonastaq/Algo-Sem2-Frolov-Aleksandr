#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<std::pair<int, int>>> graph(n + 1);

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    graph[u].push_back({w, v});
    graph[v].push_back({w, u});
  }

  std::vector<bool> is_used(n + 1, false);

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> Q;

  Q.push({0, 1});
  int answer = 0;

  while (!Q.empty()) {
    auto vertex = Q.top();
    Q.pop();

    if (!is_used[vertex.second]) {
      is_used[vertex.second] = true;
      answer += vertex.first;

      for (auto edge : graph[vertex.second]) {
        if (!is_used[edge.second]) {
          Q.push({edge.first, edge.second});
        }
      }
    }
  }

  std::cout << answer;

  return 0;
}
