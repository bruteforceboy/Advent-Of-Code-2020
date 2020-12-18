#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("OperationOrderIn.txt", "r", stdin);
  string s;
  long long res = 0;
  while (getline(cin, s)) {
    int n = s.length();
    vector<pair<int, char>> stack;
    long long ans = 0;
    string ops = "*+";
    char op = '#';
    for (int i = 0; i < n; i++) {
      if (ops.find(s[i]) != string::npos) {
        op = s[i];
      } else if (isdigit(s[i])) {
        if (op == '#') {
          ans = s[i] - '0';
        } else {
          if (op == '+') {
            ans += (s[i] - '0');
          } else {
            ans *= (s[i] - '0');
          }
        }
      } else if (s[i] == '(') {
        stack.emplace_back(ans, op);
        ans = 0;
        op = '#';
      } else if (s[i] == ')') {
        if (!stack.empty()) {
          auto [last, c] = stack.back();
          stack.pop_back();
          if (c == '+') {
            ans += last;
          } else if (c == '*') {
            ans *= last;
          }
        }
      }
    }
    res += ans;
  }
  cout << res << '\n';
  return 0;
}