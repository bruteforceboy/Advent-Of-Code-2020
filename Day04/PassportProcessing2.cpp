#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<string>& words) {
  bool ok = true;
  for (string& word : words) {
    string type = word.substr(0, word.find(":"));
    string str = word.substr(word.find(":") + 1);
    if (type == "byr") {
      if (stoi(str) < 1920 || stoi(str) > 2002)
        ok = false;
    } else if (type == "iyr") {
      if (stoi(str) < 2010 || stoi(str) > 2020)
        ok = false;
    } else if (type == "eyr") {
      if (stoi(str) < 2020 || stoi(str) > 2030)
        ok = false;
    } else if (type == "hgt") {
      string suffix = str.substr(max(0, (int) str.size() - 2));
      if (suffix.empty() || (suffix != "cm" && suffix != "in")) {
        ok = false;
      } else if (suffix == "cm") {
        int num = stoi(str.substr(0, (int) str.size() - 2));
        if (num < 150 || num > 193)
          ok = false;
      } else {
        int num = stoi(str.substr(0, (int) str.size() - 2));
        if (num < 59 || num > 76)
          ok = false;
      }
    } else if (type == "hcl") {
      if (str[0] != '#') {
        ok = false;
      } else {
        str = str.substr(1);
        if ((int) str.length() != 6)
          ok = false;
        else {
          string chars = "0123456789abcdef";
          for (char& c : str) {
            if (chars.find(c) == string::npos) {
              ok = false;
            }
          }
        }
      }
    } else if (type == "ecl") {
      if (str != "amb" && str != "blu" && str != "brn" && str != "gry" && str != "grn"
          && str != "hzl" && str != "oth")
        ok = false;
    } else if (type == "pid") {
      if ((int) str.length() != 9)
        ok = false;
      else {
        for (char c : str) {
          if (c < '0' || c > '9') {
            ok = false;
          }
        }
      }
    }
  }
  return ok;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("PassportProcessingIn2.txt", "r", stdin);
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
        bool ok = isValid(words);
        for (string& word : words)
          mp[word.substr(0, word.find(":"))] = true;
        if ((int) mp.size() == 8 && ok) {
          ++valid;
        } else if ((int) mp.size() == 7 && mp["cid"] == false && ok) {
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
  bool ok = isValid(words);
  for (string& word : words) {
    mp[word.substr(0, word.find(":"))] = true;
  }
  if ((int) mp.size() == 8 && ok) {
    ++valid;
  } else if ((int) mp.size() == 7 && mp["cid"] == false && ok) {
    ++valid;
  }
  cout << valid << '\n';
  return 0;
}