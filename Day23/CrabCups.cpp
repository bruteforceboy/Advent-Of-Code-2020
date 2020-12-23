#include <bits/stdc++.h>
using namespace std;

/*
 * all this is unnecessary
 * just playing around with modulos
 * look at part 2 for the main solution
 */

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> nums{9, 5, 2, 3, 1, 6, 4, 8, 7};
  int n = nums.size();
  for (int i = 0; i < 100; i++) {
    vector<int> next;
    for (int j = 1; j <= 3; j++) {
      next.push_back(nums[(i + j) % n]);
    }
    map<int, bool> vis;
    for (int p : next) {
      vis[p] = true;
    }
    int x = nums[i % n], cur = x - 1;
    while (true) {
      if (cur <= 0) {
        cur = n;
      }
      if (!vis.count(cur)) {
        break;
      }
      --cur;
    }
    int id = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == cur) {
        id = i;
      }
    }
    vector<int> nnums = nums;
    int d = 4, count = 0;
    while (true) {
      int cur = (i + d) % n, to = ((cur - 3) % n + n) % n;
      swap(nnums[cur], nnums[to]);
      if (cur == id) {
        break;
      }
      ++d;
      ++count;
    }
    for (int j = 1; j <= 3; j++) {
      nnums[(i + j + count + 1) % n] = nums[(i + j) % n];
    }
    nums = nnums;
  }
  for (int i = 0; i < n; i++) {
    if (nums[i] == 1) {
      for (int j = 1; j <= 8; j++) {
        cout << nums[(i + j)] % n;
      }
      cout << '\n';
    }
  }
  return 0;
}