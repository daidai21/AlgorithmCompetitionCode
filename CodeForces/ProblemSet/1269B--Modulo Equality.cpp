#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main () {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0, tmp; i < n; ++i) {
        cin >> tmp;
        a[i] = tmp;
    }
    for (int i = 0, tmp; i < n; ++i) {
        cin >> tmp;
        b[i] = tmp;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; ++i) {
        int tmp = b[i] - a[0];
        tmp = (tmp + m) % m;
        bool flag = true;
        // check valid
        for (int j = 0; j < n; ++j) {
            if ((b[(i + j) % n] - a[j] + m) % m != tmp) {
                flag = false;
                break;
            }
        }
        // if valid; cout
        if (flag) {
            cout << tmp << endl;
            break;
        }
    }

    return 0;
}
