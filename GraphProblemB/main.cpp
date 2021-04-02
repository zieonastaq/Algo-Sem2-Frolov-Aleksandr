#include <iostream>
#include <vector>

int timer = 0;

std::vector<std::vector<int>> g;
std::vector<bool> used;
std::vector<int> before, after;

void dfs(int v) {
  used[v] = true;
  before[v] = timer++;
  for (auto to : g[v]) {
    if (!used[to]) {
      dfs(to);
    }
  }
  after[v] = timer++;
}

bool is_ancestor(int u, int v) {
  return (before[u] < before[v]) && (after[v] < after[u]);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  g = std::vector<std::vector<int>>(n + 1);
  used = std::vector<bool>(n + 1);
  before = std::vector<int>(n + 1);
  after = std::vector<int>(n + 1);

  int root;

  for (int i = 1; i <= n; i++) {
    int father;
    std::cin >> father;
    if (father == 0) {
      root = i;
    } else {
      g[father].push_back(i);
    }
  }

  dfs(root);

  int m;
  std::cin >> m;

  while (m-- > 0) {
    int a, b;
    std::cin >> a >> b;
    std::cout << (int) is_ancestor(a, b) << '\n';
  }

  return 0;
}
