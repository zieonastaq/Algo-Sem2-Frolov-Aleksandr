#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> g;
std::vector<char> color;
std::vector<int> parent;

bool have_cycle = false;

void print_cycle(int end, int start) {
  have_cycle = true;
  std::cout << "YES\n";
  std::vector<int> ans;
  while (end != start) {
    ans.push_back(end);
    end = parent[end];
  }
  std::reverse(ans.begin(), ans.end());
  for (auto i : ans) {
    std::cout << i << ' ';
  }
  std::cout << end << '\n';
}

void dfs(int v, int p = -1) {
  if (have_cycle) {
    return;
  }
  parent[v] = p;
  color[v] = 'g';
  for (auto to : g[v]) {
    if (color[to] == 'g') {
      return print_cycle(v, to);
    } else if (color[to] == 'w') {
      dfs(to, v);
      if (have_cycle) {
        return;
      }
    }
  }
  color[v] = 'b';
}

////

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  g = std::vector<std::vector<int>>(n + 1);

  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v);
  }

  parent = std::vector<int>(n + 1);
  color = std::vector<char>(n + 1, 'w');

  for (int i = 1; i <= n; ++i) {
    if (color[i] == 'w') {
      dfs(i);
    }
  }

  if (!have_cycle) {
    std::cout << "NO";
  }

  return 0;
}
