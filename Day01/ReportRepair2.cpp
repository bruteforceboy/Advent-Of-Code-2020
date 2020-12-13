#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("ReportRepairIn.txt", "r", stdin);
  int n; 
  vector<int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  map<int, long long> mp;
  int m = nums.size();
  for (int i = 0; i < m; i++) {
    int rem = 2020 - nums[i];
    if (mp.count(rem)) {
      cout << 1ll * nums[i] * mp[rem] << '\n';
      return 0;
    }
    for (int j = i + 1; j < m; j++) {
      mp[nums[i] + nums[j]] = 1ll * nums[i] * nums[j];
    }
  }
  return 0;
}