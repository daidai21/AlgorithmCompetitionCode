/*

https://leetcode-cn.com/circle/discuss/TWO4Z5/
https://zhuanlan.zhihu.com/p/338806463

圆环上有10个点，编号为0~9。从0出发，每次可以逆时针和顺时针走一步，问走n步回到0共有多少种走法。

输入: 2
输出: 2
解释：有2种方案。分别是0->1->0和0->9->0

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int backToOrigin(int n, int circularNodeNum = 10) {
        std::vector< std::vector<int> > dp(n + 1, std::vector<int>(circularNodeNum, 0));
        dp[0][0] = 1;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 0; j < circularNodeNum; ++j) {
                dp[i][j] = dp[i - 1][(j - 1 + circularNodeNum) % circularNodeNum] + dp[i - 1][(j + 1) % circularNodeNum];
            }
        }
        return dp[n][0];
    }
};

int main() {
    Solution solution;
    cout << solution.backToOrigin(2) << std::endl;
}
