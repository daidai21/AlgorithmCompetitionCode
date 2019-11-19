// https://codeforces.com/problemset/problem/466/C


#include <iostream>


using namespace std;


int a[500005];
long long int sum_a[500005];


int main() {
  int n;
  cin >> n;
  long long int sum_all = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum_a[i] = sum_a[i - 1] + a[i];
    sum_all += a[i];
  }

  long long int tmp1 = 0, tmp2 = 0;
  for (int i = 1; i < n; ++i) {
    if (sum_a[i] * 3 == 2 * sum_all)
      tmp2 += tmp1;
    if (sum_a[i] * 3 == sum_all)
      tmp1++;
  }
  cout << tmp2 << endl;

  return 0;
}
