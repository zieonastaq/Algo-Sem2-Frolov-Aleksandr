#include<algorithm>
#include<iostream>
#include<vector>

std::vector<int> temp;

int do_temp(int x) {
  if (x == temp[x]) {
    return x;
  }

  return temp[x] = do_temp(temp[x]);
}

struct Edge {
  int from, to, weight;

  Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}

  Edge() = default;

  bool operator<(const Edge& another) const {
    return weight < another.weight;
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;

  temp = std::vector<int>(n + 1);

  for (int i = 1; i <= n; ++i) {
    temp[i] = i;
  }

  std::vector<Edge> edges(m);

  for (auto& k : edges) {
    int u, v, w;
    std::cin >> u >> v >> w;
    k = Edge(u, v, w);
  }

  sort(edges.begin(), edges.end());

  int s = 0;
  long long ans = 0;

  for (int i = 0; i < m && s < n - 1; ++i) {
    int u = do_temp(edges[i].from);
    int v = do_temp(edges[i].to);

    if (u != v) {
      u = do_temp(u);
      v = do_temp(v);

      if (u != v) {
        temp[u] = v;
      }

      s++;
      ans += edges[i].weight;
    }
  }

  std::cout << ans;

  return 0;
}