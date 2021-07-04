// https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b?tpId=37&&tqId=21314&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
// 请计算n*m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。

#include <iostream>

int recursion(int n, int m) {
    if (n == 0 || m == 0) {
        return 1;
    } else {
        return recursion(n - 1, m) + recursion(n, m - 1);
    }
}

int main() {
    int n, m;
    while (std::cin >> n >> m) {
        std::cout << recursion(n, m) << std::endl;
    }
}
