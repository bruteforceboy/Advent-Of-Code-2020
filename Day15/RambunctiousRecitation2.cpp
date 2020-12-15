#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <map>
#include <vector>
#include <iostream>
using namespace std;

int main() {
  vector<int> a{6, 3, 15, 13, 1, 0};
  map<int, vector<int>> mp;
  for (int i = 0; i < 6; i++) 
    mp[a[i]].push_back(i);
  int prev = 0, m = 3e7;
  for (int i = 6; i < m; i++) {
    int last = prev;
    int next;
    if ((int) mp[last].size() == 1)
      next = 0;
    else 
      next = mp[last][1] - mp[last][0];
    if ((int) mp[next].size() == 2) 
      mp[next][0] = mp[next][1], mp[next][1] = i;
    else
      mp[next].push_back(i);
    prev = next; 
  }
  cout << prev << '\n';
  return 0;
}