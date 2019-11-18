#include <iostream>
#include <vector>
#include <map>


using namespace std;


int main() {
  long long int cnt[100001], dp[100002];
  int n, res = -100000;
  cin >> n;
  for (int i = 0, tmp; i < n; ++i) {
    cin >> tmp;
    cnt[tmp]++;
    res = max(res, tmp);
  }

  dp[0] = 0;
  dp[1] = cnt[1] * 1;
  for (int i = 2; i <= res; ++i)
    dp[i] = dp[i - 1] > dp[i - 2] + i * cnt[i] ? dp[i - 1] : dp[i - 2] + i * cnt[i];
  cout << dp[res] << endl;

  return 0;
}


