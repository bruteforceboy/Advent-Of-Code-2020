#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("JurassicJigsawIn.txt", "r", stdin);
  vector<vector<string>> grid;
  string s;
  vector<string> cur;
  vector<int> nums;
  while (getline(cin, s)) {
    if (s[0] == 'T') {
      nums.push_back(stoi(s.substr(s.find("e") + 1)));
      if (!cur.empty()) {
        grid[(int) grid.size() - 1] = cur;
      }
      cur.clear();
      grid.resize((int) grid.size() + 1);
    } else {
      if (!s.empty()) {
        cur.push_back(s);
      }
    }
  }
  grid[(int) grid.size() - 1] = cur;
  int n = grid.size(), m = grid[0].size();
  vector<vector<string>> ngrid;
  auto row = [&](int idx, int row) {
    string res;
    for (int i = 0; i < m; i++) {
      res += ngrid[idx][row][i];
    }
    return res;
  };
  auto col = [&](int idx, int col) {
    string res;
    for (int i = 0; i < m; i++) {
      res += ngrid[idx][i][col];
    }
    return res;
  };
  auto flip = [&](int idx) {
    for (int i = 0; i < m / 2; i++) {
      swap(ngrid[idx][i], ngrid[idx][m - i - 1]);
    }
  };
  auto rotate = [&](int idx) {
    vector<string> cur = ngrid[idx];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        ngrid[idx][j][m - i - 1] = cur[i][j];
      }
    }
  };
  auto canPlace = [&](int x, int y, int dir) {
    if (dir == -1) {
      return (row(x, 0) == row(y, m - 1));
    }
    return (col(x, 0) == col(y, m - 1));
  };
  auto solve = [&](int idx) {
    int k = sqrt(n);
    vector<vector<int>> result(k, vector<int>(k));
    vector<bool> matched(n);
    matched[idx] = true;
    result[0][0] = idx;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        if (i > 0 || j > 0) {
          bool left = (j > 0), up = (i > 0);
          bool found = false;
          for (int x = 0; x < n && !found; x++) {
            if (!matched[x]) {
              for (int r = 0; r < 4 && !found; r++) {
                for (int f = 0; f < 2 && !found; f++) {
                  bool ok = true;
                  if (left) {
                    ok &= canPlace(x, result[i][j - 1], 1);
                  }
                  if (up) {
                    ok &= canPlace(x, result[i - 1][j], -1);
                  }
                  if (ok) {
                    result[i][j] = x;
                    matched[x] = true;
                    found = true;
                    break;
                  }
                  flip(x);
                }
                if (!found) {
                  rotate(x);
                }
              }
            }
          }
          if (!found) {
            return;
          }
        }
      }
    }
    long long res = 1ll * nums[result[0][0]] * nums[result[0][k - 1]] * nums[result[k - 1][0]] * nums[result[k - 1][k - 1]];
    cout << res << '\n';
    exit(0);
  };
  for (int i = 0; i < n; i++) {
    ngrid = grid;
    for (int r = 0; r < 4; r++) {
      for (int f = 0; f < 2; f++) {
        solve(i);
        flip(i);
      }
      rotate(i);
    }
  }
  return 0;
}