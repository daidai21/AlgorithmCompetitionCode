// 题目： 2有一个m*n的棋盘，棋盘每个格子放了不同额度的现金，从棋盘的左上⻆每次只能往右，或者往下走一步，最后达到棋盘的右下⻆ 3求哪条路能得到总金额最大，打印出路线下标
// https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        for (int i = 1; i < grid.size(); ++i) grid[i][0] += grid[i - 1][0];
        for (int j = 1; j < grid[0].size(); ++j) grid[0][j] += grid[0][j - 1];
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                grid[i][j] += std::max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};
