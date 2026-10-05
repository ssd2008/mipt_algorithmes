#include <cstdint>
#include <iostream>
#include <vector>

const int cByte = 256;
const int cCountBytes = 8;
const int cBitsInByte = 8;

void LSD(std::vector<uint64_t>& a) {
  int n = static_cast<int>(a.size());
  std::vector<uint64_t> result(n);

  for (int byte = 0; byte < cCountBytes; byte++) {
    int count[cByte] = {};

    int shift = byte * cBitsInByte;

    for (auto x : a) {
      int digit = (x >> shift) & (cByte - 1);
      ++count[digit];
    }

    int position[cByte] = {};

    for (int i = 1; i < cByte; i++) {
      position[i] = position[i - 1] + count[i - 1];
    }

    for (auto x : a) {
      int digit = (x >> shift) & (cByte - 1);

      result[position[digit]] = x;
      ++position[digit];
    }

    a.swap(result);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<uint64_t> a(n);

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  LSD(a);

  for (auto x : a) {
    std::cout << x << '\n';
  }
}