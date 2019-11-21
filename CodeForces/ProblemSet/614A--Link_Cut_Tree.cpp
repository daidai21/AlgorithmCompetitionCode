// https://codeforces.com/problemset/problem/614/A


#include <iostream>


using namespace std;


int main() {
  long long int l, r, k;
  cin >> l >> r >> k;

  bool have = false;
  long long int x = 1;
  while (x <= r) {
    if (x >= l) {
      cout << x << " ";
      have = true;
    }
    if (x > r / k)
      break;
    x *= k;
  }
  if (!have)
    cout << "-1\n" << endl;

  return 0;
}

