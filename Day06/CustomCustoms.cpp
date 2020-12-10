#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("CustomCustomsIn.txt", "r", stdin);
  char c;
  string text;
  vector<string> words;
  int count = 0, res = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == ' ') {
      if (!text.empty()) {
        words.push_back(text);
      }
      if (c == '\n') {
        ++count;
      } else {
        count = 0;
      }
      if (count == 2) {
        set<char> s;
        for (string& word : words) {
          for (char& c : word) {
            s.insert(c);
          }
        }
        res += (int) s.size();
        words.clear();
        count = 0;
      }
      text = "";
    } else {
      text += c;
      count = 0;
    }
  }
  set<char> s;
  for (string& word : words) {
    for (char& c : word) {
      s.insert(c);
    }
  }
  res += (int) s.size();
  cout << res << '\n';
  return 0;
}