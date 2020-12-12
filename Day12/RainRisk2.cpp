#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("RainRiskIn2.txt", "r", stdin);
  string s;
  int x = 0, y = 0, nx = 10, ny = 1;
  vector<pair<int, int>> moves = {
    {1, 0},
    {0, -1},
    { -1, 0},
    {0, 1}
  };
  vector<pair<int, int>> dir = {
    {1, 1},
    {1, -1},
    { -1, -1},
    { -1, 1}
  };
  int d = 0;
  while (cin >> s) {
    char c = s[0];
    int move = stoi(s.substr(1));
    if (c == 'E') {
      nx += moves[0].first * move;
      ny += moves[0].second * move;
    } else if (c == 'S') {
      nx += moves[1].first * move;
      ny += moves[1].second * move;
    } else if (c == 'W') {
      nx += moves[2].first * move;
      ny += moves[2].second * move;
    } else if (c == 'N') {
      nx += moves[3].first * move;
      ny += moves[3].second * move;
    } else if (c == 'F') {
      x = x + nx * move;
      y = y + ny * move;
    } else if (c == 'R') {
      move /= 90;
      int d = (move + 4) % 4;
      if (move % 2)
        swap(nx, ny);
      nx = nx * dir[d].first;
      ny = ny * dir[d].second;
    } else {
      move /= 90;
      int d = (4 - move) % 4;
      if (move % 2)
        swap(nx, ny);
      nx = nx * dir[d].first;
      ny = ny * dir[d].second;
    }
  }
  cout << abs(x) + abs(y) << '\n';
  return 0;
}