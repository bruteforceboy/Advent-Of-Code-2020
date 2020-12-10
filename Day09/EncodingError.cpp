#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("EncodingErrorIn.txt", "r", stdin);
  int n;
  vector<int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  for (int i = 25; i < (int) nums.size(); i++) {
    bool ok = false;
    for (int j = i - 25; j < i; j++) {
      for (int k = j + 1; k < i; k++) {
        ok |= nums[j] + nums[k] == nums[i];
      }
    }
    if (!ok) {
      cout << nums[i] << '\n';
      break;
    }
  }
  return 0;
}