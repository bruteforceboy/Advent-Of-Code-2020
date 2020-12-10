#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("HandHeldHaltingIn.txt", "r", stdin);
  string s;
  vector<pair<string, pair<char, int>>> commands;
  while (cin >> s) {
    char op;
    cin >> op;
    int n;
    cin >> n;
    commands.emplace_back(s, make_pair(op, n));
  }
  int len = commands.size(), acc = 0;
  vector<bool> vis(len);
  for (int i = 0; i < len; i++) {
    if (vis[i]) {
      break;
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
  cout << acc << '\n';
  return 0;
}