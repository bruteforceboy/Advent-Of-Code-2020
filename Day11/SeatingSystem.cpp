#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("SeatingSystemIn.txt", "r", stdin);
  vector<string> grid;
  string s;
  while (cin >> s) {
    grid.push_back(s);
  } 
  int n = grid.size(), m = grid[0].size();
  while (1) {
    vector<vector<bool>> change(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) if (grid[i][j] != '.') {
        int empty = 0, occupied = 0;
        vector<int> dx{-1, 0, 1, 0, -1, 1, -1, 1}, dy{0, 1, 0, -1, -1, 1, 1, -1};
        for (int k = 0; k < 8; k++) {
          int nx = i + dx[k], ny = j + dy[k];
          if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (grid[nx][ny] == 'L')
              ++empty;
            else if (grid[nx][ny] == '#')
              ++occupied;
          }
        }
        if (grid[i][j] == 'L') {
          if (occupied == 0) {
            change[i][j] = true;
          }
        } else {
          if (occupied >= 4) {
            change[i][j] = true;
          }
        }
      }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (change[i][j]) {
          ++count;
          grid[i][j] = grid[i][j] == '#' ? 'L' : '#';
        }
      }
    }
    if (count == 0) {
      int res = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          res += grid[i][j] == '#';
        }
      }
      cout << res << '\n';
      return 0;
    }
  }
  return 0;
}