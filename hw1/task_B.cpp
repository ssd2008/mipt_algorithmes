#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  std::cin >> n;

  std::vector<double> prefix_log(n + 1);

  for (int i = 0; i < n; i++) {
    double value;
    std::cin >> value;
    prefix_log[i + 1] = prefix_log[i] + std::log(value);
  }

  int q;
  std::cin >> q;

  const int cPrecision = 6;
  std::cout << std::fixed;
  std::cout.precision(cPrecision);

  for (int i = 0; i < q; i++) {
    int left;
    int right;
    std::cin >> left >> right;

    double mean_log =
        (prefix_log[right + 1] - prefix_log[left]) / (right - left + 1);

    std::cout << std::exp(mean_log) << n;
  }
}
