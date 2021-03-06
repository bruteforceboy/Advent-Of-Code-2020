#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("ConwayCubesIn.txt", "r", stdin);
  vector<string> in;
  string s;
  while (cin >> s) {
    in.push_back(s);
  }
  int n = in.size(), m = in[0].size();
  map<tuple<int, int, int, int>, char> grid;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (in[i][j] == '#') {
        grid[{0, 0, i, j}] = in[i][j];
      }
    }
  }
  for (int itr = 0; itr < 6; itr++) {
    map<tuple<int, int, int, int>, char> ngrid;
    for (auto& [tup, _] : grid) {
      int x = get<0>(tup), y = get<1>(tup), z = get<2>(tup), w = get<3>(tup);
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          for (int dz = -1; dz <= 1; dz++) {
            for (int dw = -1; dw <= 1; dw++) {
              int nx = x + dx, ny = y + dy, nz = z + dz, nw = w + dw, active = 0;
              for (int tx = -1; tx <= 1; tx++) {
                for (int ty = -1; ty <= 1; ty++) {
                  for (int tz = -1; tz <= 1; tz++) {
                    for (int tw = -1; tw <= 1; tw++) {
                      if (abs(tx) + abs(ty) + abs(tz) + abs(tw) > 0) {
                        if (grid.count({nx + tx, ny + ty, nz + tz, nw + tw})) {
                          ++active;
                        }
                      }
                    }
                  }
                }
              }
              if (grid.count({nx, ny, nz, nw})) {
                if (active == 2 || active == 3) {
                  ngrid[{nx, ny, nz, nw}] = '#';
                } 
              } else {
                if (active == 3) {
                  ngrid[{nx, ny, nz, nw}] = '#';
                }
              }
            }
          }
        }
      }
    }
    grid = ngrid;
  }
  int res = 0;
  for (auto& [tup, _] : grid) {
    if (_ == '#') {
      ++res;
    }
  }
  cout << res << '\n';
  return 0;
}