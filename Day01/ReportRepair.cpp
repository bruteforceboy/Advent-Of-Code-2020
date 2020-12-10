#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("ReportRepairIn.txt", "r", stdin);
  int n;
  map<int, bool> mp;
  while (cin >> n) {
    if (mp.count(2020 - n)) {
      cout << n * (2020 - n) << '\n';
      return 0;
    }
    mp[n] = true;
  } 
  return 0;
}