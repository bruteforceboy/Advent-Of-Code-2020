#include <bits/stdc++.h>
using namespace std;

struct Field {
  string str;
  int l1, r1, l2, r2;

  Field(string s, int x, int y, int a, int b) {
    str = s;
    l1 = x;
    r1 = y;
    l2 = a;
    r2 = b;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("TicketTranslationIn.txt", "r", stdin);
  string s;
  int parseType = 0;
  map<int, vector<int>> mp;
  vector<Field> fields;
  vector<vector<int>> tickets;
  int fieldId = 0;
  auto parse = [&](string str, int type) {
    if (str.empty()) {
      return;
    }
    if (type == 0) {
      string pre = str.substr(0, str.find(":"));
      int l1 = stoi(str.substr(str.find(":") + 2, str.find("-") - str.find(":")));
      int r1 = stoi(str.substr(str.find("-") + 1, str.rfind("o") - str.find("-")));
      int l2 = stoi(str.substr(str.rfind("r") + 2, str.rfind("-") - str.rfind("r")));
      int r2 = stoi(str.substr(str.rfind("-") + 1));
      fields.emplace_back(pre, l1, r1, l2, r2);
      for (int i = l1; i <= r1; i++) {
        mp[i].push_back(fieldId);
      }
      for (int i = l2; i <= r2; i++) {
        mp[i].push_back(fieldId);
      }
      ++fieldId;
    } else {
      string cur = "";
      int sz = tickets.size();
      tickets.resize(sz + 1);
      for (char& c : str) {
        if (c == ',') {
          tickets[sz].push_back(stoi(cur));
          cur = "";
        } else {
          cur += c;
        }
      }
      tickets[sz].push_back(stoi(cur));
    }
  };
  while (getline(cin, s)) {
    if (s == "your ticket:") {
      parseType = 1;
    } else if (s == "nearby tickets:") {
      parseType = 1;
    } else {
      parse(s, parseType);
    }
  }
  int tSize = tickets.size();
  vector<bool> valid(tSize, true);
  int len;
  for (int i = 0; i < tSize; i++) {
    for (int num : tickets[i]) {
      if (mp[num].empty()) {
        valid[i] = false;
      }
    }
    if (valid[i]) {
      len = tickets[i].size();
    }
  }
  vector<set<int>> lenCandidates(len);
  for (int i = 0; i < len; i++) {
    int fSize = fields.size();
    for (int j = 0; j < fSize; j++) {
      bool ok = true;
      for (int k = 0; k < tSize; k++) {
        if (valid[k]) {
          int l1 = fields[j].l1, r1 = fields[j].r1, l2 = fields[j].l2, r2 = fields[j].r2;
          ok &= ((tickets[k][i] >= l1 && tickets[k][i] <= r1) || (tickets[k][i] >= l2 && tickets[k][i] <= r2));
        }
      }
      if (ok) {
        lenCandidates[i].insert(j);
      }
    }
  }
  vector<int> res;
  vector<bool> matched(len);
  vector<int> ans(20, -1);
  vector<vector<int>> dp(20, vector<int>((1 << 20), -1));
  function<void(int, int)> solve = [&](int idx, int mask) {
    if (idx == 20) {
      long long res = 1;
      for (int i = 0; i < 20; i++) {
        if (ans[i] < 6) {
          res *= tickets[0][i];
        }
      }
      cout << res << '\n';
      return;
    }
    if (dp[idx][mask] != -1) {
      return;
    }
    for (int i = 0; i < len; i++) {
      if (!matched[i]) {
        if (lenCandidates[i].count(idx)) {
          matched[i] = true;
          ans[i] = idx;
          mask |= (1 << i);
          solve(idx + 1, mask);
          mask ^= (1 << i);
          matched[i] = false;
          ans[i] = -1;
        }
      }
    }
    dp[idx][mask] = 1;
  };
  solve(0, 0);
  return 0;
}