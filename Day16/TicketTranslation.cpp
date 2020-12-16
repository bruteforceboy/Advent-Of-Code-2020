#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("TicketTranslationIn.txt", "r", stdin);
  string s;
  int parseType = 0;
  map<int, bool> mp;
  vector<int> nums;
  auto parse = [&](string str, int type) {
    if (str.empty()) {
      return;
    }
    if (type == 0) {
      int l1 = stoi(str.substr(str.find(":") + 2, str.find("-") - str.find(":")));
      int r1 = stoi(str.substr(str.find("-") + 1, str.rfind("o") - str.find("-")));
      int l2 = stoi(str.substr(str.rfind("r") + 2, str.rfind("-") - str.rfind("r")));
      int r2 = stoi(str.substr(str.rfind("-") + 1));
      for (int i = l1; i <= r1; i++) {
        mp[i] = true;
      }
      for (int i = l2; i <= r2; i++) {
        mp[i] = true;
      }
    } else {
      string cur = "";
      for (char& c : str) {
        if (c == ',') {
          nums.push_back(stoi(cur));
          cur = "";
        } else {
          cur += c;
        }
      }
      nums.push_back(stoi(cur));
    }
  };
  while (getline(cin, s)) {
    if (s == "your ticket:") {
      getline(cin, s);
    } else if (s == "nearby tickets:") {
      parseType = 1;
    } else {
      parse(s, parseType);
    }
  }
  int res = 0;
  for (int p : nums) {
    if (!mp.count(p)) {
      res += p;
    }
  } 
  cout << res << '\n';
  return 0;
}