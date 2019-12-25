// https://codeforces.com/problemset/problem/788/A


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  vector<int> b(n);
  for (int i = 0; i < n - 1; ++i)
    b[i] = abs(a[i] - a[i + 1]);
  vector<vector<long long int>> dp(2, vector<long long int>(n));
  dp[1][0] = b[0];
  dp[0][0] = 0;
  long long int res = dp[1][0];
  for (int i = 1; i < n - 1; ++i) {
    dp[1][i] = max(0LL + b[i], dp[0][i - 1] + b[i]);
    dp[0][i] = dp[1][i - 1] - b[i];
    res = max(res, dp[1][i]);
    res = max(res, dp[0][i]);
  }
  cout << res << endl;

  return 0;
}


/*
// overtime


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int result = 0;
  for (int l = 0; l < n - 1; ++l) {
    for (int r = l + 1; r < n; ++r) {
      int f_sum = 0;
      for (int i = l; i < r; ++i) {
        f_sum += abs(a[i] - a[i + 1]) * pow(-1, i - l);
      }
      result = max(result, f_sum);
    }
  }
  cout << result << endl;

  return 0;
}
*/
