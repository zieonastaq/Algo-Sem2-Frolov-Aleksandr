#include <iostream>
#include <vector>
#include <set>

struct Edge {
  int vertex;
  int cost;
  Edge(int to, int cost) : vertex(to), cost(cost) {}
};

const int INF = 1e9;
std::vector<std::vector<Edge>> edges;

int findDistance(int start, int finish, int n) {
  std::vector<int> answer(n, INF);
  answer[start] = 0;
  std::set<std::pair<int, int>> st = {{answer[start], start}};

  while (!st.empty()) {
    auto t = *st.begin();
    st.erase(t);

    for (auto edge : edges[t.second]) {
      if (t.first + edge.cost < answer[edge.vertex]) {
        st.erase({answer[edge.vertex], edge.vertex});
        answer[edge.vertex] = t.first + edge.cost;
        st.insert({answer[edge.vertex], edge.vertex});
      }
    }
  }

  return answer[finish];
}

int main() {
  int n = 0, m = 0, s = 0, f = 0;
  std::cin >> n >> m >> s >> f;
  --s, --f;

  edges = std::vector<std::vector<Edge>>(n);

  for (int i = 0; i < m; i++) {
    int u, v, cost;
    std::cin >> u >> v >> cost;
    --u, --v;
    edges[u].push_back(Edge(v, cost));
    edges[v].push_back(Edge(u, cost));
  }

  int ans = findDistance(s, f, n);

  if (ans == INF) {
    std::cout << -1;
  } else {
    std::cout << ans;
  }

  return 0;
}