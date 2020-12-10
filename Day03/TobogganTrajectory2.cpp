#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("TobogganTrajectoryIn2.txt", "r", stdin);
  string s;
  vector<string> grid;
  while (getline(cin, s)) {
    grid.push_back(s);
  }
  vector<pair<int, int>> moves = {
    {1, 1},
    {3, 1},
    {5, 1},
    {7, 1},
    {1, 2}
  };
  vector<int> res(5);
  int n = grid.size(), m = grid[0].size();
  for (int i = 0; i < 5; i++) {
    int r = 0, c = 0;
    while (r < n) {
      res[i] += (grid[r][c] == '#');
      c += moves[i].first;
      c %= m;
      r += moves[i].second;
    }
  }
  long long result = 1ll;
  for (int p : res) {
    result *= p;
  }
  cout << result << '\n';
  return 0;
}