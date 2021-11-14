#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

# M*N矩阵 每行升序 找第k大的值
class Solution:
    def theKrdMaxValueOnMatrix(self, mat, k):
        if len(mat) == 0:
            return None
        if k <= 0 or len(mat) * len(mat[0]) < k:
            return None
        mp = [len(mat[0]) - 1 for _ in range(len(mat))]  # 每行最大值的索引
        # 去掉最大的前k-1个元素
        for i in range(k - 1):
            curRow = 0
            for row in range(1, len(mat)):
                if mp[row] >= 0 and mat[curRow][mp[curRow]] < mat[row][mp[row]]:
                    curRow = row
                mp[curRow] -= 1
        # 找每行最大的元素作比较
        theKrdRowIdx = 0
        for row in range(1, len(mat)):
            if mp[row] >= 0 and mat[theKrdRowIdx][mp[theKrdRowIdx]] < mat[row][mp[row]]:
                theKrdRowIdx = row
        return mat[theKrdRowIdx][mp[theKrdRowIdx]]


if __name__ == '__main__':
    tmp = [
        [1, 2, 3],
        [3, 4, 5]
    ]
    s = Solution()
    print(s.theKrdMaxValueOnMatrix(tmp, 0))
    print(s.theKrdMaxValueOnMatrix(tmp, 1))
    print(s.theKrdMaxValueOnMatrix(tmp, 2))
    print(s.theKrdMaxValueOnMatrix(tmp, 3))
    print(s.theKrdMaxValueOnMatrix(tmp, 4))
    print(s.theKrdMaxValueOnMatrix(tmp, 5))
    print(s.theKrdMaxValueOnMatrix(tmp, 6))
    print(s.theKrdMaxValueOnMatrix(tmp, 7))
