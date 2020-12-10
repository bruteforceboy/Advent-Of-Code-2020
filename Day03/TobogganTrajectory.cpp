#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("TobogganTrajectoryIn.txt", "r", stdin);
  string s;
  vector<string> grid;
  while (getline(cin, s)) {
    grid.push_back(s);
  } 
  int n = grid.size(), m = grid[0].size();
  int r = 0, c = 0, result = 0;
  for (int i = 0; i < n; i++) {
    result += (grid[r][c] == '#');
    c += 3;
    c %= m;
    ++r;
  }
  cout << result << '\n';
  return 0;
}