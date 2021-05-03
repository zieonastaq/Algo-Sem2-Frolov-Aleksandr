#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

struct Edge {
  long long first;
  long long second;
  long long dist;

  Edge() = default;

  Edge(long long first, long long to, long long dist) : first(first), second(to), dist(dist) {}
};

const long long INF = 3 * 1e18;

long long n;

std::vector<bool> is_used;
std::vector<Edge> edges;
std::vector<std::vector<Edge>> g;
std::vector<long long> dist;

void dfs(long long v) {
  is_used[v] = true;

  for (auto edge : g[v]) {
    if (!is_used[edge.second]) {
      dfs(edge.second);
    }
  }
}

std::vector<std::pair<char, long long>> getAns() {
  std::vector<long long> dist_copy = dist;
  std::vector<std::pair<char, long long>> ans(n);

  for (auto t : edges) {
    if (dist[t.first] != INF) {
      dist[t.second] = std::min(dist[t.second], dist[t.first] + t.dist);
    }
  }

  for (long long i = 0; i < n; ++i) {
    if (dist[i] != dist_copy[i]) {
      if (!is_used[i]) {
        dfs(i);
      }
    }
  }

  for (long long i = 0; i < n; ++i) {
    if (dist_copy[i] == INF) {
      ans[i].first = '*';
    } else if (is_used[i]) {
      ans[i].first = '-';
    } else {
      ans[i].first = '+';
      ans[i].second = dist[i];
    }
  }

  return ans;
}

void FloydBellman(long long v) {
  dist[v] = 0;

  for (long long i = 0; i < n - 1; ++i) {
    for (auto t : edges) {
      if (dist[t.first] != INF) {
        dist[t.second] = std::min(dist[t.second], dist[t.first] + t.dist);
      }
    }
  }
}

int main() {
  long long m, s;
  std::cin >> n >> m >> s;
  --s;

  edges = std::vector<Edge>(m);
  dist = std::vector<long long>(n, INF);
  is_used = std::vector<bool>(n, false);
  g = std::vector<std::vector<Edge>>(n, std::vector<Edge>());

  for (long long i = 0; i < m; ++i) {
    long long u, v, distance;
    std::cin >> u >> v >> distance;
    --u, --v;
    edges[i] = Edge(u, v, distance);
    g[u].push_back(edges[i]);
  }

  FloydBellman(s);

  auto ans = getAns();

  for (auto t : ans) {
    if (t.first == '+') {
      std::cout << t.second << '\n';
    } else {
      std::cout << t.first << '\n';
    }
  }

  return 0;
}