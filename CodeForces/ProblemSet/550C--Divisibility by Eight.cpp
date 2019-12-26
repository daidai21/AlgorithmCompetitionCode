// https://codeforces.com/problemset/problem/550/C

/**
 * 1000 % 8 == 0
 * The necessary and sufficient condition that x is divisible by 8 is that the last 3 digits of x are also divisible by 8.
 */

#include <iostream>
#include <string>

using namespace std;


int main() {
  string input;
  cin >> input;

  // result >= 1000
  for (int i = 0; i < input.size(); ++i) {
    for (int j = i + 1 ; j < input.size(); ++j) {
      for (int k = j + 1; k < input.size(); ++k) {
        int n = (input[i] - '0') * 100 + (input[j] - '0') * 10 + (input[k] - '0');
        if (n % 8 == 0) {
          cout << "YES" << endl;
          cout << n << endl;
          return 0;
        }
      }
    }
  }
  // 100 > result >= 10
  for (int i = 0; i < input.size() - 1; ++i) {
    for (int j = i + 1; j  < input.size(); ++j) {
      int n = (input[i] - '0') * 10 + (input[j] - '0');
      if (n % 8 == 0) {
        cout << "YES" << endl;
        cout << n << endl;
        return 0;
      }
    }
  }
  // 10 > result( == 8)
  for (int i = 0; i < input.size(); ++i) {
    int n = input[i] - '0';
    if (n % 8 == 0) {
      cout << "YES" << endl;
      cout << n << endl;
      return 0;
    }
  }
  cout << "NO" << endl;

  return 0;
}

