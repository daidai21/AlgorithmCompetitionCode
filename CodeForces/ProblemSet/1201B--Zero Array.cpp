// https://codeforces.com/problemset/problem/1201/B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  long long int sum_a = 0, max_a = 0;
  for (int n : a) {
    sum_a += n;
    max_a = max_a > n ? max_a : n;
  }
  if (sum_a % 2 == 0 && sum_a - max_a >= max_a)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
