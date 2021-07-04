#!/usr/bin/env python3
# -*- coding: UTF-8 -*-


class Solution:
    def backToOrigin(self, n, length=10):
        #点的个数为10
        dp = [[0 for i in range(length)] for j in range(n + 1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            for j in range(length):
                #dp[i][j]表示从0出发，走i步到j的方案数
                dp[i][j] = dp[i - 1][(j - 1 + length) % length] + dp[i - 1][(j + 1) % length]
        return dp[n][0]


if __name__ == '__main__':
    s = Solution()
    print(s.backToOrigin(2))
    print(s.backToOrigin(2, 13))
