// https://codeforces.com/problemset/problem/26/A


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


bool is_prime(int n) {
  if (n < 2)
    return false;
  else if (n == 2)
    return true;
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0)
      return false;
  }
  return true;
}


int prime_factors_num(int n) {
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0 && is_prime(i)) {
      cnt++;
    }
  }
  return cnt;
}


int main() {
  int n;
  cin >> n;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if ( prime_factors_num(i) == 2 ) {
      res++;
    }
  }
  cout << res << endl;

  return 0;
}
