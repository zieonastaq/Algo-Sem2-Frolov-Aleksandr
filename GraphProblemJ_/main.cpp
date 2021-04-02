#include <iostream>
#include <vector>
#include <stack>

std::vector<std::stack<int>> g;

void euler_cycle(int v) {
  while (!g[v].empty()) {
    int to = g[v].top();
    g[v].pop();
    euler_cycle(to);
    std::cout << to << ' ' << v << '\n';
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, a;
  std::cin >> n >> a;
  g = std::vector<std::stack<int>>(n + 1);

  for (int u = 1; u <= n; ++u) {
    for (int v = 1; v <= n; ++v) {
      int x;
      std::cin >> x;
      if (x == 0 && u != v) {
        g[v].push(u);
      }
    }
  }

  euler_cycle(a);

  return 0;
}
