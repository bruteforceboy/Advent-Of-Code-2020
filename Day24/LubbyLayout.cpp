#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("LubbyLayoutIn.txt", "r", stdin);
  string s;
  map<pair<int, int>, int> mp;
  while (cin >> s) {  
    int x = 0, y = 0, n = s.length();
    for (int i = 0; i < n; i++) {
      if (s[i] == 'n' || s[i] == 's') {
        string dir = s.substr(i, 2);
        if (dir == "ne") {
          --x;
        } else if (dir == "nw") {
          --x;
          --y;
        } else if (dir == "se") {
          ++x;
          ++y;
        } else {
          ++x;
        }
        ++i;
      } else {
        if (s[i] == 'e') {
          ++y;
        } else {
          --y;
        }
      }
    }
    mp[{x, y}]++;
  }
  int res = 0;
  for (auto& [_, cnt] : mp) {
    if (cnt % 2) {
      ++res;
    }
  }
  cout << res << '\n';
  return 0;
}