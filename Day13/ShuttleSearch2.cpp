#include <bits/stdc++.h>
using namespace std;

/*
 * chinese remainder theorem + prime factorization 
 */

#define int long long

int inv(int a, int m) {
  int m0 = m, t, q;
  int x0 = 0, x1 = 1;

  if (m == 1)
    return 0;

  while (a > 1) {
    q = a / m;
    t = m;
    m = a % m, a = t;
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }
  if (x1 < 0)
    x1 += m0;

  return x1;
}

int crt(int num[], int rem[], int k) {
  int prod = 1;
  for (int i = 0; i < k; i++) 
    prod *= num[i];
  int result = 0;
  for (int i = 0; i < k; i++) {
    int pp = prod / num[i];
    result += rem[i] * inv(pp, num[i]) * pp;
  }
  return result % prod;
}


int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("ShuttleSearchIn.txt", "r", stdin);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<int, int>> nums;
  string cur;
  int count = 0;
  for (char& c : s) {
    if (c != ',') {
      cur += c;
    } else {
      if (cur != "x") {
        nums.emplace_back(stoi(cur), count);
      }
      ++count;
      cur = "";
    }
  }
  if (cur != "x") {
    nums.emplace_back(stoi(cur), count);
  }
  auto getPrimes = [&](int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        res.push_back(i);
        while (n % i == 0) {
          n /= i;
        }
      }
    }
    if (n >= 2) {
      res.push_back(n);
    }
    return res;
  };
  map<int, set<int>> mp;
  int m = nums.size();
  for (int i = 0; i < m; i++) {
    auto [x, y] = nums[i];
    int a = ((x - (y + 1)) % x + x) % x, b = x;
    vector<int> fact = getPrimes(b);
    for (auto& prime : fact) {
      mp[prime].insert(a);
    }
  }
  vector<pair<int, int>> v;
  for (auto& [u, s] : mp) {
    if ((int) s.size() > 1) {
      cout << "No\n";
    }
    v.emplace_back(*s.begin(), u);
  }
  int sz = (int) v.size();
  int num[sz], rem[sz];
  for (int i = 0; i < sz; i++) {
    auto [x, y] = v[i];
    num[i] = y;
    rem[i] = x;
  }
  cout << crt(num, rem, sz) + 1 << '\n';
  return 0;
}