#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("CustomCustomsIn2.txt", "r", stdin);
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
        map<char, int> mp;
        for (string& word : words) {
          map<char, bool> seen;
          for (char& c : word) {
            seen[c] = true;
          }
          for (char c = 'a'; c <= 'z'; c++) {
            if (seen.count(c)) {
              ++mp[c];
            }
          }
        }
        int m = words.size(), same = 0;
        for (char c = 'a'; c <= 'z'; c++) {
          if (mp[c] == m) {
            ++same;
          }
        }
        res += same;
        words.clear();
        count = 0;
      }
      text = "";
    } else {
      text += c;
      count = 0;
    }
  }
  words.push_back(text);
  map<char, int> mp;
  for (string& word : words) {
    map<char, bool> seen;
    for (char& c : word) {
      seen[c] = true;
    }
    for (char c = 'a'; c <= 'z'; c++) {
      if (seen.count(c)) {
        ++mp[c];
      }
    }
  }
  int m = words.size(), same = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    if (mp[c] == m) {
      ++same;
    }
  }
  res += same;
  cout << res << '\n';
  return 0;
}