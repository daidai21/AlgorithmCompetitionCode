// https://codeforces.com/problemset/problem/158/C


#include <iostream>
#include <string>


using namespace std;


int main() {
  int n;
  cin >> n;
  string cur_path = "/";
  string input;
  string tmp;
  for (int i = 0; i < n; ++i) {
    cin >> input;
    if (input == "pwd")
      cout << cur_path << endl;
    else {
      cin >> input;
      input += '/';
      for (int j = 0; j < input.size(); ++j) {
        tmp += input[j];
        if (input[j] == '/') {
          if (tmp == "/") {
            cur_path = tmp;
          } else if (tmp == "../") {
            for (int k = cur_path.length() - 1; cur_path[k - 1] != '/'; --k) {
              cur_path.resize(k);
            }
            cur_path.resize(cur_path.size() - 1);
          } else {
            cur_path += tmp;
          }
          tmp = "";
        }
      }
    }
  }

  return 0;
}
