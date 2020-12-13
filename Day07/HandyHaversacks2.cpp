#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("HandyHaversacksIn.txt", "r", stdin);
  string s;
  map<string, vector<pair<string, int>>> graph;
  while (cin >> s) {
    string col, bags, contain;
    cin >> col >> bags >> contain;
    while (1) {
      string num;
      cin >> num;
      string a, b, c;
      if (num == "no") {
        cin >> a >> b;
        break;
      } else {
        cin >> a >> b >> c;
        graph[s + col].push_back({a + b, stoi(num)});
        if (c.back() == '.') {
          break;
        }
      }
    }
  }
  map<string, bool> vis;
  function<long long(string)> dfs = [&](string node) {
    vis[node] = true;
    long long res = 0;
    for (auto& [to, num] : graph[node]) {
      res += num;
      res += 1ll * num * dfs(to);
    }
    return res;
  };
  cout << dfs("shinygold") << '\n';
  return 0;
}