#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("OperationOrderIn.txt", "r", stdin);
  string s;
  long long res = 0;
  while (getline(cin, s)) {
    int n = s.length();
    vector<char> opStack;
    vector<vector<long long>> nums;
    long long ans = 1;
    string ops = "*+";
    for (int i = 0; i < n; i++) {
      if (ops.find(s[i]) != string::npos) {
        opStack.push_back(s[i]);
      } else if (isdigit(s[i])) {
        if (nums.empty()) {
          nums.push_back({});
          nums.back().push_back(s[i] - '0');
        } else if (nums.back().empty() || opStack.back() != '+') {
          nums.back().push_back(s[i] - '0');
        } else {
          if (opStack.back() == '+') { 
            long long last = nums.back().back();
            nums.back().pop_back();
            nums.back().push_back(last + (s[i] - '0'));
            opStack.pop_back();
          }
        }
      } else if (s[i] == '(') {
        nums.push_back({});
      } else if (s[i] == ')') {
        vector<long long> last = nums.back();
        for (int k = 0; k < (int) last.size() - 1; k++) {
          opStack.pop_back();
        }
        long long prod = 1;
        for (long long val : last) {
          prod *= val;
        }
        nums.pop_back();
        if (nums.empty()) {
          nums.push_back({prod});
        } else if (nums.back().empty() || opStack.empty()) {
          nums.back().push_back(prod);
        } else {
          char op = opStack.back();
          long long last = nums.back().back();
          if (op == '+') {
            nums.back().pop_back();
            nums.back().push_back(prod + last);
            opStack.pop_back();
          } else {
            nums.back().push_back(prod);
          }
        } 
      }
    }
    for (long long p : nums.back()) {
      ans *= p;
    }
    res += ans;
  } 
  cout << res << '\n';
  return 0;
}