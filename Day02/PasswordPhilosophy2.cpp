#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("PasswordPhilosophyIn2.txt", "r", stdin);
  string s;
  int result = 0;
  while (getline(cin, s)) {
    int mn = stoi(s.substr(0, s.find('-')));
    int mx = stoi(s.substr(s.find('-') + 1, (s.find(":") - 3)  - s.find('-')));
    char ch = s[s.find(":") - 1];
    string str = s.substr(s.find(":") + 2);
    if ((int) str.length() >= mx && ((str[mn - 1] == ch) ^ (str[mx - 1] == ch))) {
      ++result;
    }
  }
  cout << result << '\n';
  return 0;
}