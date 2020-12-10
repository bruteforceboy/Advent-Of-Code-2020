#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("HandheldHaltingIn2.txt", "r", stdin);
  string s;
  vector<pair<string, pair<char, int>>> commands;
  while (cin >> s) {
    char op;
    cin >> op;
    int n;
    cin >> n;
    commands.emplace_back(s, make_pair(op, n));
  }
  int m = commands.size(), acc = 0;
  auto can = [&]() {
    vector<bool> vis(m);
    acc = 0;
    for (int i = 0; i < m; i++) {
      if (vis[i]) {
        return false;
      } else {
        vis[i] = true;
      }
      auto [cmd, _] = commands[i];
      auto [op, n] = _;
      if (cmd == "nop") {
        continue;
      } else {
        if (cmd == "acc") {
          if (op == '+') {
            acc += n;
          } else {
            acc -= n;
          }
        } else {
          if (op == '+') {
            i = i + n - 1;
          } else {
            i = i - n - 1;
          }
        }
      }
    }
    return true;
  };
  for (int i = 0; i < m; i++) {
    if (commands[i].first == "nop") {
      commands[i].first = "jmp";
      if (can()) {
        cout << acc << '\n';
        return 0;
      }
      commands[i].first = "nop";
    } else if (commands[i].first == "jmp") {
      commands[i].first = "nop";
      if (can()) {
        cout << acc << '\n';
        return 0;
      }
      commands[i].first = "jmp";
    }
  }
  cout << acc << '\n';
  return 0;
}