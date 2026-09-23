#include <iomanip>
#include <iostream>
#include <vector>

int FuncRes(std::vector<int>& a, std::vector<int>& b, int x) {
  int left_bound = 0;
  int right_bound = a.size() - 1;
  while (left_bound + 1 < right_bound) {
    int mid = (left_bound + right_bound) / 2;
    if (a[mid] + x - b[mid] < 0) {
      left_bound = mid;
    } else {
      right_bound = mid;
    }
  }

  if (b[left_bound] < a[right_bound] + x) {
    return left_bound + 1;
  }
  return right_bound + 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<int> b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    int x;
    std::cin >> x;
    std::cout << FuncRes(a, b, x) << '
';
  }
}
