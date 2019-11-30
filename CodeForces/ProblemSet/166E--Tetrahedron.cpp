// https://codeforces.com/problemset/problem/166/E


#include <iostream>


using namespace std;


#define MOD 1000000007


int main() {
  int n;
  cin >> n;
  long long int x = 0;
  for (int i = 2; i <= n; ++i) {
    if (i & 1)
      x = (x * 3 - 3) % MOD;
    else
      x = (x * 3 + 3) % MOD;
  }
  cout << x << endl;

  return 0;
}


/*
  find law
*/
