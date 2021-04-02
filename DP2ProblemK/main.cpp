#include <iostream>
#include <vector>

bool check(long long i, long long j, long long m) {
  long long checker1 = -1, checker2 = -1;

  for (size_t k = 0; k < m; ++k) {
    if (checker1 == checker2 &&
        checker1 == i % 2 && checker1 == j % 2) {
      return false;
    }

    checker1 = i % 2;
    checker2 = j % 2;
    i /= 2;
    j /= 2;
  }

  return true;
}

int main() {
  long long n, m;
  std::cin >> n >> m;

  if (m > n) {
    std::swap(m, n);
  }

  long long power2m = 1 << m;

  std::vector<std::vector<long long>> dp(n, std::vector<long long>(power2m));

  for (auto &i : dp[0]) {
    i = 1;
  }

  for (long long k = 1; k < n; ++k) {
    for (long long i = 0; i < power2m; ++i) {
      for (long long j = 0; j < power2m; ++j) {
        if (check(i, j, m)) {
          dp[k][i] += dp[k - 1][j];
        }
      }
    }
  }

  long long ans = 0;

  for (auto i : dp.back()) {
    ans += i;
  }

  std::cout << ans;

  return 0;
}
