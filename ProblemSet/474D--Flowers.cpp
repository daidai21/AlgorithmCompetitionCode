// https://codeforces.com/problemset/problem/474/D

#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007
#define MAX_N 100001

int main() {
  int t ,k;
  cin >> t >> k;
  vector<int> dp(MAX_N, 1);
  for (int i = k; i < MAX_N; ++i) {
    dp[i] = dp[i - 1] + dp[i - k];
    dp[i] %= MOD;
  }
  vector<int> pre_sum(MAX_N + 1, 0);
  for (int i = 1; i < MAX_N + 1; ++i) {
    pre_sum[i] = pre_sum[i - 1] + dp[i];
    pre_sum[i] %= MOD;
  }
  int a, b;
  for (int i = 0; i < t; ++i) {
    cin >> a >> b;
    cout << (pre_sum[b] - pre_sum[a - 1] + MOD) % MOD << endl;
  }

  return 0;
}
