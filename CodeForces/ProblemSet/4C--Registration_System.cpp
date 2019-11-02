// https://codeforces.com/problemset/problem/4/C

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
  unordered_map<string, int> hash;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string tmp;
    cin >> tmp;
    if (hash.find(tmp) == hash.end()) {
      hash[tmp] = 1;
      cout << "OK" << endl;
    } else {
      cout << tmp << hash[tmp] << endl;
      hash[tmp]++;
    }
  }
  return 0;
}
