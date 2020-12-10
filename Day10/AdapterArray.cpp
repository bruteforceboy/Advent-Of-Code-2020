#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("AdapterArrayIn.txt", "r", stdin);
  int n;
  int mx = 0;
  map<int, bool> mp;
  while (cin >> n) {
    mp[n] = true;
    mx = max(mx, n);
  }
  mp[mx + 3] = true;
  int cur = 0;
  vector<int> res(4);
  outer: while (1) {
    for (int i = 1; i <= 3; i++) {
      if (mp.count(cur + i)) {
        ++res[i];
        cur = cur + i;
        goto outer;
      }
    } 
    break;
  } 
  cout << res[1] * res[3] << '\n';
  return 0;
}