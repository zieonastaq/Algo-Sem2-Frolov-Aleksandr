#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long long W, H, N;
  std::cin >> W >> H >> N;

  if (W * H > 5 * N) {
    std::cout << "No";
    return 0;
  }

  int changer_x[] = {0, -1, 0, 0, 1};
  int changer_y[] = {0, 0, -1, 1, 0};
  std::vector<std::vector<bool>> field(W, std::vector<bool>(H));

  int x_pos, y_pos;

  while (N-->0) {
    std::cin >> x_pos >> y_pos;
    --x_pos, --y_pos;

    for (int i = 0; i < 5; ++i) {
      if (x_pos + changer_x[i] >= 0 && x_pos + changer_x[i] < W &&
          y_pos + changer_y[i] >= 0 && y_pos + changer_y[i] < H) {
        field[x_pos + changer_x[i]][y_pos + changer_y[i]] = true;
      }
    }
  }

  bool is_painted = true;

  for (auto& i : field) {
    for (auto j : i) {
      is_painted &= j;
    }
  }

  std::cout << (is_painted ? "Yes" : "No");

  return 0;
}
