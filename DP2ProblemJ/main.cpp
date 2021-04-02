#include <iostream>
#include <vector>

const long long MOD = 999999937;

class Matrix {
 public:
  Matrix(bool is_E) {
    if (is_E) {
      base_table = {{1, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0},
                    {0, 0, 1, 0, 0},
                    {0, 0, 0, 1, 0},
                    {0, 0, 0, 0, 1}};
    } else {
      base_table = {{1, 1, 1, 1, 1},
                    {1, 1, 1, 1, 1},
                    {1, 1, 1, 0, 0},
                    {1, 1, 1, 1, 1},
                    {1, 1, 1, 0, 0}};
    }
  }

  Matrix& operator*=(const Matrix& right_operand) {
    std::vector<std::vector<long long>> buff_table(5, std::vector<long long>(5));
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        long long sum = 0;
        for (int k = 0; k < 5; ++k) {
          sum = ((base_table[i][k] * right_operand.base_table[k][j]) % MOD + sum) % MOD;
        }

        buff_table[i][j] = sum;
      }
    }
    base_table = buff_table;
    return *this;
  }

  std::vector<std::vector<long long>> base_table;
};

Matrix bin_pow(const Matrix& A, long long n) {
  if (n == 0) {
    return Matrix(true);
  }

  if (n == 1) {
    return A;
  }

  if (n % 2 == 0) {
    Matrix B = bin_pow(A, n / 2);
    return B *= B;
  } else {
    Matrix B = bin_pow(A, n / 2);
    B *= B;
    B *= A;
    return B;
  }
}

int main() {

  long long n;
  std::cin >> n;

  Matrix A(false);

  while (n != 0) {
    Matrix res = bin_pow(A, n);
    long long sum = 0;
    for (int k = 0; k < 5; ++k) {
      sum = (res.base_table[0][k] + sum) % MOD;
    }
    std::cout << sum << '\n';
    std::cin >> n;
  }

  return 0;
}
