#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("EncodingErrorIn.txt", "r", stdin);
  int n;
  vector<long long> nums;
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
      long long target = nums[i];
      int l = 0;
      long long sum = 0;
      for (int j = 0; j < (int) nums.size(); j++) {
        sum += nums[j];
        while (sum > target)
          sum -= nums[l++];
        if (sum == target) {
          long long mn = nums[l], mx = nums[l];
          for (int k = l; k <= j; k++) {
            mn = min(mn, nums[k]);
            mx = max(mx, nums[k]);
          } 
          cout << mn + mx << '\n';
          return 0;
        }
      }
    }
  }
  return 0;
}