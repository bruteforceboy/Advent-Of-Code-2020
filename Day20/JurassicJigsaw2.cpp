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
  auto flipMat = [](vector<vector<char>>& mat) {
    int m = mat.size();
    for (int i = 0; i < m / 2; i++) {
      swap(mat[i], mat[m - i - 1]);
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
  auto rotateMat = [](vector<vector<char>>& mat) {
    int m = (int) mat.size();
    vector<vector<char>> res(m, vector<char>(m));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        res[j][m - i - 1] = mat[i][j];
      }
    }
    mat = res;
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
    int sz = (m - 2) * k;
    vector<vector<char>> mat(sz, vector<char>(sz));
    int rx = 0, ry = 0;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        int g = result[i][j];
        for (int x = 1; x < m - 1; x++) {
          for (int y = 1; y < m - 1; y++) {
            mat[rx + x - 1][ry + y - 1] = ngrid[g][x][y];
          }
        }
        ry += m - 2;
      }
      rx += m - 2;
      ry = 0;
    }
    int hashtags = 0;
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        hashtags += (mat[i][j] == '#');
      }
    }
    int res = 0;
    for (int r = 0; r < 4; r++) {
      for (int f = 0; f < 2; f++) {
        vector<pair<int, int>> moves = {
          {0, 0},
          {1, 1},
          {1, 4},
          {0, 5},
          {0, 6},
          {1, 7},
          {1, 10},
          {0, 11}, 
          {0, 12},
          {1, 13},
          {1, 16}, 
          {0, 17},
          {-1, 18}, 
          {0, 18},
          {0, 19} 
        };
        for (int i = 0; i < sz; i++) {
          for (int j = 0; j < sz; j++) {
            bool ok = true;
            for (auto& [x, y] : moves) {
              int nx = i + x, ny = j + y;
              if (nx >= 0 && nx < sz && ny >= 0 && ny < sz) {
                ok &= (mat[nx][ny] == '#');
              } else {
                ok = false;
              }
            }
            if (ok) {
              res += (int) moves.size();
            }
          }
        }
        flipMat(mat);
      }
      rotateMat(mat);
    }
    cout << hashtags - res << '\n';
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