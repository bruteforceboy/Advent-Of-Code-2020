#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("PassportProcessingIn.txt", "r", stdin);
  char c;
  string text;
  vector<string> words;
  int count = 0, valid = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n') {
      if (!text.empty()) {
        words.push_back(text);
      }
      text = "";
      if (c == '\n') {
        ++count;
      } else {
        count = 0;
      }
      if (count == 2) {
        map<string, bool> mp;
        for (string& word : words) {
          mp[word.substr(0, word.find(":"))] = true;
        }
        if ((int) mp.size() == 8) {
          ++valid;
        } else if ((int) mp.size() == 7 && mp["cid"] == false) {
          ++valid;
        }
        count = 0;
        words.clear();
      }
    } else {
      text += c;
      count = 0;
    }
  }
  words.push_back(text);
  map<string, bool> mp;
  for (string& word : words) {
    mp[word.substr(0, word.find(":"))] = true;
  }
  if ((int) mp.size() == 8) {
    ++valid;
  } else if ((int) mp.size() == 7 && mp["cid"] == false) {
    ++valid;
  }
  cout << valid << '\n';
  return 0;
}