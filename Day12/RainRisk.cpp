#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("RainRiskIn.txt", "r", stdin);
  string s;
  int x = 0, y = 0;
  vector<pair<int, int>> moves = {
    {1, 0}, 
    {0, -1}, 
    {-1, 0},
    {0, 1} 
  };
  int idx = 0;
  while (cin >> s) {
    char c = s[0];
    int move = stoi(s.substr(1));
    if (c == 'E') {
      x += moves[0].first * move;
      y += moves[0].second * move;
    } else if (c == 'S') {
      x += moves[1].first * move;
      y += moves[1].second * move;
    } else if (c == 'W') {
      x += moves[2].first * move;
      y += moves[2].second * move;
    } else if (c == 'N') {
      x += moves[3].first * move;
      y += moves[3].second * move;
    } else if (c == 'F') {
      x += moves[idx].first * move;
      y += moves[idx].second * move;  
    } else if (c == 'R') {
      move /= 90;
      idx = (idx + move) % 4;
    } else {
      move /= 90;
      idx = ((idx - move) % 4 + 4) % 4;
    }
  } 
  cout << abs(x) + abs(y) << '\n';
  return 0;
}