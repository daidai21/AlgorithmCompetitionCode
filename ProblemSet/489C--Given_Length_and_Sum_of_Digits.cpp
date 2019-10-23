// https://codeforces.com/problemset/problem/489/C

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int m, s;
  cin >> m >> s;
  if (m == 1 && s == 0)
    cout << "0 0" << endl;
  else if (s == 0 || s > m * 9)
    cout << "-1 -1" << endl;
  else {
    string min_, max_;
    for (int i = 0; i < m; ++i) {
      int tmp = min(9, s);
      s -= tmp;
      max_ += tmp + '0';
    }
    min_ = max_;
    reverse(min_.begin(), min_.end());
    if (min_[0] == '0')
      for (int i = 0; i < m; ++i)
        if (min_[i] != '0') {
          ++min_[0];
          --min_[i];
          break;
        }
    cout << min_ << " " << max_ << endl;
  }

  return 0;
}
