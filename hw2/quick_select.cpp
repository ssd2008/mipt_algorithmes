#include <iostream>
#include <vector>

int Median5(int x1, int x2, int x3, int x4, int x5) {
  if (x5 < x1) {
    std::swap(x5, x1);
  }
  if (x4 < x1) {
    std::swap(x4, x1);
  }
  if (x3 < x1) {
    std::swap(x3, x1);
  }
  if (x2 < x1) {
    std::swap(x2, x1);
  }

  if (x5 < x2) {
    std::swap(x5, x2);
  }
  if (x4 < x2) {
    std::swap(x4, x2);
  }
  if (x3 < x2) {
    std::swap(x3, x2);
  }

  if (x4 < x3) {
    std::swap(x4, x3);
  }
  if (x5 < x3) {
    std::swap(x5, x3);
  }

  return x3;
}

int MedianLess5(std::vector<int> a) {
  int n = static_cast<int>(a.size());

  for (int i = 0; i < n; i++) {
    for (int j = 0; j + 1 < n - i; j++) {
      if (a[j + 1] < a[j]) {
        std::swap(a[j], a[j + 1]);
      }
    }
  }

  return a[(n - 1) / 2];
}

int QuickSelect(std::vector<int>& a, int k);

int ChoosePivot(std::vector<int>& a) {
  int n = static_cast<int>(a.size());
  if (n <= 5) {
    if (n == 5) {
      return Median5(a[0], a[1], a[2], a[3], a[4]);
    }
    return MedianLess5(a);
  }

  std::vector<int> medians;
  medians.reserve((n + 4) / 5);

  for (int i = 0; i < n; i += 5) {
    int len = std::min(5, n - i);
    if (len == 5) {
      medians.push_back(Median5(a[i], a[i + 1], a[i + 2], a[i + 3], a[i + 4]));
    } else {
      std::vector<int> last_group(a.begin() + i, a.end());
      medians.push_back(MedianLess5(last_group));
    }
  }
  int median_k = (static_cast<int>(medians.size()) + 1) / 2;
  return QuickSelect(medians, median_k);
}

int QuickSelect(std::vector<int>& a, int k) {
  int n = static_cast<int>(a.size());
  if (n == 1) {
    return a[0];
  }

  int pivot = ChoosePivot(a);
  std::vector<int> less;
  std::vector<int> equal;
  std::vector<int> greater;

  for (auto x : a) {
    if (x < pivot) {
      less.push_back(x);
    } else if (x == pivot) {
      equal.push_back(x);
    } else {
      greater.push_back(x);
    }
  }
  int less_size = static_cast<int>(less.size());
  int equal_size = static_cast<int>(equal.size());

  if (k <= less_size) {
    return QuickSelect(less, k);
  }
  if (k <= less_size + equal_size) {
    return pivot;
  }
  return QuickSelect(greater, k - less_size - equal_size);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  int k;
  int a0;
  int a1;

  std::cin >> n >> k >> a0 >> a1;

  std::vector<int> a(n);
  a[0] = a0;
  if (n > 1) {
    a[1] = a1;
  }

  const int c1 = 123;
  const int c2 = 45;
  const int mod = 10004321;

  for (int i = 2; i < n; i++) {
    a[i] = (a[i - 1] * c1 + a[i - 2] * c2) % mod;
  }
  std::cout << QuickSelect(a, k) << '\n';
}