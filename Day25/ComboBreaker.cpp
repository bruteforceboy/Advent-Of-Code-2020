#include <bits/stdc++.h>
using namespace std;

const int MOD = 20201227;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("ComboBreakerIn.txt", "r", stdin);
  long long a, b;
  cin >> a >> b;
  auto find = [](int num) {
    long long cur = 1, count = 0;
    for (int itr = 0; itr < MOD; itr++) {
      cur = (cur * 7) % MOD;
      ++count;
      if (cur == num) {
        return count;
      }
    }
    return -1ll;
  };
  auto transform = [](int a, int b) {
    long long res = 1;
    for (int i = 0; i < b; i++) {
      res = (res * a) % MOD;
    }
    return res;
  };  
  int y = find(b), ans = transform(a, y);
  cout << ans << '\n';
  return 0;
}