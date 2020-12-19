#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("MonsterMessagesIn2.txt", "r", stdin);
  string s;
  map<int, string> mp;
  map<int, vector<vector<int>>> children;
  vector<string> messages;
  while (getline(cin, s)) {
    if (s.find(":") != string::npos) {
      int num = stoi(s.substr(0, s.find(":")));
      if (s.find("\"") != string::npos) {
        string suffix = s.substr(s.find("\"") + 1, 1);
        mp[num] = suffix;
      } else {
        s = s.substr(s.find(":") + 2);
        vector<int> nums;
        int cur = 0;
        for (char c : s) {
          if (c == ' ') {
            if (cur > 0) {
              nums.push_back(cur);
            }
            cur = 0;
          } else if (c == '|') {
            children[num].push_back(nums);
            nums.clear();
          } else {
            cur = (cur * 10) + (c - '0');
          }
        }
        nums.push_back(cur);
        children[num].push_back(nums);
      }
    } else {
      messages.push_back(s);
    }
  }
  map<pair<string, int>, bool> dp;
  function<bool(string, int)> ok = [&](string s, int source) {
    int n = s.length();
    if (mp.count(source)) {
      return (s == mp[source]);
    }
    if (dp.count({s, source})) {
      return dp[{s, source}];
    }
    for (auto& v : children[source]) {
      int parts = (int) v.size();
      if (parts == 1) {
        if (ok(s, v[0])) {
          return dp[{s, source}] = true;
        }
      } else if (parts == 2) {
        for (int i = 0; i < n - 1; i++) {
          if (ok(s.substr(0, i + 1), v[0]) && ok(s.substr(i + 1), v[1])) {
            return dp[{s, source}] = true;
          }
        }
      } else {
        assert(parts == 3);
        for (int i = 0; i < n; i++) {
          for (int j = i + 1; j < n; j++) if (n - j > 0) {
            if (ok(s.substr(0, i + 1), v[0]) && ok(s.substr(i + 1, j - i), v[1]) && ok(s.substr(j + 1, n - j), v[2])) {
              return dp[{s, source}] = true;
            }
          }
        }
      }
    }
    return dp[{s, source}] = false;
  };
  int res = 0;
  for (string& str : messages) {
    if (ok(str, 0)) {
       ++res;
    }
    map<pair<string, int>, bool> ndp;
    dp = ndp;
  }
  cout << res << '\n';
  return 0;
}