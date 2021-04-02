#include <iostream>
#include <vector>
#include <set>

std::vector<std::vector<int>> g;
std::vector<bool> used;
std::vector<int> d, up;
std::set<int> points;
int timer = 1;

void dfs(int v, int p = -1) {
  int children_counter = 0;
  used[v] = true;
  d[v] = up[v] = timer;

  ++timer;

  for (auto to : g[v]) {
    if (to != p) {
      if (used[to]) {
        up[v] = std::min(up[v], d[to]);
      } else {
        dfs (to, v);
        up[v] = std::min(up[v], up[to]);

        if ((up[to] >= d[v]) && (p != -1)) {
          points.insert(v);
        }

        children_counter++;
      }
    }
  }

  if (p == -1 && children_counter > 1) {
    points.insert(v);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  g = std::vector<std::vector<int>>(n + 1);
  used = std::vector<bool>(n + 1);
  d = std::vector<int>(n + 1);
  up = std::vector<int>(n + 1);

  while (m-- > 0) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      dfs(i);
    }
  }

  std::cout << points.size() << '\n';
  for (auto i : points) {
    std::cout << i << ' ';
  }

  return 0;
}
