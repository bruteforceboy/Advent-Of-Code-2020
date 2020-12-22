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
  auto win = [](deque<int> v1) {
    long long res = 0;
    for (int i = 0; i < (int) v1.size(); i++) {
      res += ((int) v1.size() - i) * v1[i];
    }
    cout << res << endl;
    exit(0);
  };
  function<int(deque<int>&, deque<int>&)> solve = [&](deque<int>& v1, deque<int>& v2) {
    map<pair<deque<int>, deque<int>>, bool> dp;
    while (!v1.empty() && !v2.empty()) {  
      if (dp.count(make_pair(v1, v2))) {
        return 0;
      }
      dp[make_pair(v1, v2)] = true;
      int p1 = v1.front(), p2 = v2.front();
      v1.pop_front();
      v2.pop_front();
      if (p1 <= (int) v1.size() && p2 <= (int) v2.size()) {
        deque<int> v3, v4;
        for (int i = 0; i < p1; i++) {
          v3.push_back(v1[i]);
        }
        for (int i = 0; i < p2; i++) {
          v4.push_back(v2[i]);
        }
        int winner = solve(v3, v4);
        if (winner == 0) {
          v1.push_back(p1);
          v1.push_back(p2);
         } else {
          v2.push_back(p2);
          v2.push_back(p1);
        }
      } else {
        if (p1 > p2) {
          v1.push_back(p1);
          v1.push_back(p2);
        } else {
          v2.push_back(p2);
          v2.push_back(p1);
        }
      }
    }
    if (v1.empty()) { 
      return 1; 
    }
    return 0;
  };
  solve(cards[0], cards[1]);
  if (cards[0].empty()) {
    win(cards[1]);
  } else {
    win(cards[0]);
  }
  return 0;
}