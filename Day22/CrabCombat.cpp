#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("CrabCombatIn.txt", "r", stdin);
  string s;
  vector<deque<int>> cards(2);
  int idx = -1;
  while (getline(cin, s)) {
    if (s.empty()) {
      continue;
    } else if (s[0] == 'P') {
      ++idx;
    } else {
      cards[idx].push_back(stoi(s));
    }
  } 
  while (!cards[0].empty() && !cards[1].empty()) {
    int p1 = cards[0].front(), p2 = cards[1].front();
    cards[0].pop_front();
    cards[1].pop_front();
    if (p1 > p2) {
      cards[0].push_back(p1);
      cards[0].push_back(p2);
    } else {
      cards[1].push_back(p2);
      cards[1].push_back(p1);
    }
  }
  long long res = 0;
  for (int i = 0; i < (int) cards[0].size(); i++) {
    res += ((int) cards[0].size() - i) * cards[0][i];
  }
  for (int i = 0; i < (int) cards[1].size(); i++) {
    res += ((int) cards[1].size() - i) * cards[1][i];
  }
  cout << res << '\n';
  return 0;
}