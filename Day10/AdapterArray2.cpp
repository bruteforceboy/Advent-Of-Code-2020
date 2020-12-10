#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("AdapterArrayIn2.txt", "r", stdin);
  int n;
  int mx = 0;
  map<int, bool> mp;
  while (cin >> n) {
    mp[n] = true;
    mx = max(mx, n);
  }
  mp[mx + 3] = true;
  vector<long long> dp(mx + 4, -1);
  function<long long(int)> dfs = [&](int n) {
    if (n == mx + 3) {
      return 1ll;
    }
    if (dp[n] != -1) {
      return dp[n];
    }
    long long res = 0;
    for (int i = 1; i <= 3; i++) {
      if (mp.count(n + i)) {
        res += dfs(n + i);
      }
    }
    return dp[n] = res;
  };
  cout << dfs(0) << '\n';
  return 0;
}