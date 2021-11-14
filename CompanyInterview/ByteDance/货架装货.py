#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

"""
10个货架，每个有不同的容量， 现在需要存储x容量物品， 最少需要多少货架， 且需要的货架最好不空。返回需要的货架坐标的index。
货架容量是从小到大排序好的
[5, 4, 3, 3, 2, 1] 10 [0, 2, 4]
[5, 4, 3, 3, 2, 1] 11 [0, 2, 3]
"""
class Solution:

    def slover(self, lst, cap):
        self.enumLst = []
        self.dfs(lst, cap, [], 0)
        self.enumLst = sorted(self.enumLst, key=lambda v: (-v[0], len(v[1])), reverse=False)
        return self.enumLst[0]

    def dfs(self, lst, needCap, idxs, curIdx):
        if curIdx >= len(lst):
            if needCap <= 0:
                self.enumLst.append((needCap, idxs))
            return 
        self.dfs(lst, needCap - lst[curIdx], idxs + [curIdx], curIdx + 1)
        self.dfs(lst, needCap, idxs, curIdx + 1)


if __name__ == '__main__':
    tmp = [5, 4, 3, 3, 2, 1]
    s = Solution()
    print(s.slover(tmp, 10))
    print(s.slover(tmp, 11))
