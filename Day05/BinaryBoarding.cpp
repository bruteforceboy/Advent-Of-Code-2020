#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("BinaryBoardingIn.txt", "r", stdin);
  string s;
  auto binSearch = [&](int lo, int hi, string str) {
    int idx = 0;
    while (lo < hi) {
      int mid = lo + hi >> 1;
      if (str[idx] == 'F' || str[idx] == 'L') {
        hi = mid;
      } else {
        lo = mid + 1;
      }
      ++idx;
    }
    return lo;
  };
  long long mx = 0;
  while (cin >> s) {
    long long a = binSearch(0, 127, s.substr(0, 7));
    long long b = binSearch(0, 7, s.substr(7));
    mx = max(mx, 8 * a + b);
  }
  cout << mx << '\n';
  return 0;
}