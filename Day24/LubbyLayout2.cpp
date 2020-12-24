#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("LubbyLayoutIn.txt", "r", stdin);
  string str;
  set<pair<int, int>> s;
  while (cin >> str) {  
    int x = 0, y = 0, n = str.length();
    for (int i = 0; i < n; i++) {
      if (str[i] == 'n' || str[i] == 's') {
        string dir = str.substr(i, 2);
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
        if (str[i] == 'e') {
          ++y;
        } else {
          --y;
        }
      }
    }
    if (s.count({x, y})) {
      s.erase({x, y});
    } else {
      s.insert({x, y});
    }
  }
  vector<int> dx = {-1, 0, 0, -1, 1, 1}, dy = {-1, 1, -1, 0, 0, 1};
  for (int itr = 0; itr < 100; itr++) {
    set<pair<int, int>> ns;
    for (auto [x, y] : s) {
      int count = 0;
      for (int k = 0; k < 6; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (s.count({nx, ny})) {
          ++count;
        }
      }
      if (count == 1 || count == 2) {
        ns.insert({x, y});
      }
    }
    for (auto [x, y] : s) {
      for (int k = 0; k < 6; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (!s.count({nx, ny})) {
          int count = 0;
          for (int k1 = 0; k1 < 6; k1++) {
            int tx = nx + dx[k1], ty = ny + dy[k1];
            if (s.count({tx, ty})) {
              ++count;
            }
          }
          if (count == 2) {
            ns.insert({nx, ny});
          }
        }
      }
    }
    s = ns;
  }
  cout << s.size() << '\n';
  return 0;
}