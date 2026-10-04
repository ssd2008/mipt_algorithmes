#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> Merge(
    const std::vector<std::pair<int, int>>& v1,
    const std::vector<std::pair<int, int>>& v2) {
  std::vector<std::pair<int, int>> result(v1.size() + v2.size());
  std::size_t i = 0;
  std::size_t j = 0;

  while (i < v1.size() || j < v2.size()) {
    if (i < v1.size() && j < v2.size()) {
      if (v1[i].first < v2[j].first) {
        result[i + j] = v1[i];
        ++i;
      } else if (v1[i].first == v2[j].first) {
        if (v1[i].second < v2[j].second) {
          result[i + j] = v2[j];
          ++j;
        } else {
          result[i + j] = v1[i];
          ++i;
        }
      } else {
        result[i + j] = v2[j];
        ++j;
      }
    } else if (i < v1.size()) {
      result[i + j] = v1[i];
      ++i;
    } else {
      result[i + j] = v2[j];
      ++j;
    }
  }
  return result;
}

std::vector<std::pair<int, int>> MergeSort(std::vector<std::pair<int, int>> v) {
  if (v.size() <= 1) {
    return v;
  }

  std::size_t mid = v.size() / 2;
  std::vector<std::pair<int, int>> left(v.begin(), v.begin() + mid);
  std::vector<std::pair<int, int>> right(v.begin() + mid, v.end());

  left = MergeSort(left);
  right = MergeSort(right);

  return Merge(left, right);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> v(2 * n);

  for (int i = 0; i < n; i++) {
    int l;
    int r;
    std::cin >> l >> r;

    v[i * 2].first = l;
    v[i * 2].second = 1;
    v[i * 2 + 1].first = r;
    v[i * 2 + 1].second = -1;
  }

  v = MergeSort(v);
  std::vector<int> result;
  int now = 0;

  for (auto x : v) {
    if (now == 0) {
      result.push_back(x.first);
    }

    now += x.second;

    if (now == 0) {
      result.push_back(x.first);
    }
  }

  std::cout << result.size() / 2 << '\n';

  for (std::size_t i = 0; i < result.size(); i++) {
    if (i % 2 == 0) {
      std::cout << result[i] << " ";
    } else {
      std::cout << result[i] << "\n";
    }
  }
}