#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("DockingDataIn.txt", "r", stdin);
  string s;
  vector<pair<string, string>> prev;
  long long ans = 0;
  map<long long, long long> mp;
  auto process = [&]() {
    if (prev.empty()) {
      return;
    }
    string mask = prev[0].second;
    int sz = (int) mask.size();
    for (int i = 1; i < prev.size(); i++) {
      auto [x, y] = prev[i];
      int num = stoi(x);
      string bin;
      while (num) {
        bin += ((num % 2) + '0');
        num /= 2;
      }
      reverse(bin.begin(), bin.end());
      while (bin.size() < sz) {
        bin = '0' + bin;
      }
      string res(sz, '#');
      for (int i = 0; i < sz; i++) {
        if (mask[i] == 'X' || mask[i] == '1') {
          res[i] = mask[i];
        } else {
          res[i] = bin[i];
        }
      }
      reverse(res.begin(), res.end());
      int count = 0;
      long long rep = 0;
      vector<int> floating;
      for (int i = 0; i < sz; i++) {
        if (res[i] == 'X') {
          ++count;
          floating.push_back(i);
        } else {
          rep |= (((res[i] == '1') * 1ll) << i);
        }
      }
      for (int i = 0; i < (1 << count); i++) {
        long long tmp = rep;
        for (int j = 0; j < count; j++) {
          if ((i & (1ll << j))) {
            tmp |= (1ll << floating[j]);
          }
        }
        mp[tmp] = stoi(y);
      }
    }
  };
  while (getline(cin, s)) {
    if (s.substr(0, 2) == "ma") {
      process();
      prev.clear();
      string rep = s.substr(7);
      prev.emplace_back("#", rep);
    } else {
      string addr = s.substr(4, s.find("]") - 4);
      string rep = s.substr(s.find("=") + 2);
      prev.emplace_back(addr, rep);
    }
  }
  process();
  for (auto& [u, v] : mp) {
    ans += v;
  }
  cout << ans << '\n';
  return 0;
}