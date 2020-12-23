#include <bits/stdc++.h>
using namespace std;

/*
 * so basically you just keep the next value
 * for each element
 * and on delete
 * assign the deleted nodes next value to the current node as it's new next
 * value
 * same thing for the insertion
 * kinda like a linked list
 */

const int n = 1e6, moves = 10e6;
int a[n], nextValue[n + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  a[0] = 9;
  a[1] = 5;
  a[2] = 2;
  a[3] = 3;
  a[4] = 1;
  a[5] = 6;
  a[6] = 4;
  a[7] = 8;
  a[8] = 7;
  for (int i = 9; i < n; i++) {
    a[i] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    nextValue[a[i]] = a[(i + 1) % n];
  }
  auto removeNext = [&](int idx) {
    int val = nextValue[idx];
    nextValue[idx] = nextValue[val];
    return val;
  };
  auto placeNext = [&](int from, int to) {
    int val = nextValue[from];
    nextValue[to] = val;
    nextValue[from] = to;
  };
  int cur = a[0];
  for (int move = 0; move < moves; move++) {
    int a = removeNext(cur), b = removeNext(cur), c = removeNext(cur);
    int dest = cur;
    while (true) {
      --dest;
      if (dest == 0) {
        dest = n;
      }
      if (dest != a && dest != b && dest != c) {
        break;
      }
    }
    placeNext(dest, c);
    placeNext(dest, b);
    placeNext(dest, a);
    cur = nextValue[cur];
  }
  cur = 1;
  cout << 1ll * nextValue[cur] * nextValue[nextValue[cur]] << '\n';
  return 0;
}