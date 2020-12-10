#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("HandyHaversacksIn.txt", "r", stdin);
  string s;
  map<string, vector<string>> graph;
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
        graph[a + b].push_back(s + col);
        if (c.back() == '.') {
          break;
        }
      }
    }
  }
  int count = 0;
  map<string, bool> vis;
  function<void(string)> dfs = [&](string node) {
    ++count;
    vis[node] = true;
    for (string to : graph[node]) {
      if (!vis.count(to)) {
        dfs(to);
      }
    }
  };
  dfs("shinygold");
  cout << count - 1 << '\n';
  return 0;
}