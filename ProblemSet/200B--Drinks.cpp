// https://codeforces.com/problemset/problem/200/B

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, orange_juice = 0, tmp;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    orange_juice += tmp;
  }
  cout << (float)orange_juice / n << endl;

  return 0;
}
