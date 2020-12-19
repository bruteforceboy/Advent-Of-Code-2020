#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("MonsterMessagesIn.txt", "r", stdin);
  string s;
  map<int, string> mp;
  map<int, vector<vector<int>>> children;
  vector<string> messages;
  map<string, bool> message;
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
      message[s] = true;
    }
  }
  vector<string> candidates;
  function<void(int, vector<vector<string>>&, string)> solve = [&](int idx, vector<vector<string>>& ans, string str) {
    if (idx == (int) ans.size()) {
      candidates.push_back(str);
      return;
    }
    for (int i = 0; i < (int) ans[idx].size(); i++) {
      solve(idx + 1, ans, str + ans[idx][i]);
    }
  };
  map<int, vector<string>> dp;
  function<vector<string>(int)> dfs = [&](int source) -> vector<string> {
    if (mp.count(source)) {
      return vector<string>{mp[source]};
    }
    if (dp.count(source)) {
      return dp[source];
    }
    vector<string> res;
    for (auto& v : children[source]) {
      int m = v.size();
      vector<vector<string>> ans(m);
      for (int i = 0; i < m; i++) {
        ans[i] = dfs(v[i]);
      }
      candidates.clear();
      solve(0, ans, "");
      for (string& candidate : candidates) {
        res.push_back(candidate);
      }
    }
    return dp[source] = res;
  };
  vector<string> valid = dfs(0);
  int res = 0;
  for (string& str : valid) {
    if (message.count(str)) {
      ++res;
    }
  }
  cout << res << '\n';
  return 0;
}