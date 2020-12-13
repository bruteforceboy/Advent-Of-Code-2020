#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("ShuttleSearchIn.txt", "r", stdin);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> nums;
  string cur;
  int count = 0;
  for (char& c : s) {
    if (c != ',') {
      cur += c;
    } else {
      if (cur != "x") {
        nums.push_back(stoi(cur));
      }
      ++count;
      cur = "";
    }
  }
  if (cur != "x") {
    nums.push_back(stoi(cur));
  }
  int best = INT_MAX, ans = INT_MAX;
  for (auto& num : nums) {
    int need = (num - n % num) % num;
    if (need < best) {
      best = need;
      ans = num;
    } else if (need == best) {
      ans = min(ans, num);
    }
  }
  cout << ans * best << '\n';
  return 0;
}