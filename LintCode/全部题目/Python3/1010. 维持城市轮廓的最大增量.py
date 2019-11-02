class Solution:
    """
    @param grid: a 2D array
    @return: the maximum total sum that the height of the buildings can be increased
    """
    def maxIncreaseKeepingSkyline(self, grid):
        # Write your code here

        # row high list
        row_high = []
        for i in range(len(grid[0])):
            high = 0
            for j in range(len(grid)):
                high = max(high, grid[j][i])
            row_high.append(high)
        # column high list
        column_high = []
        for i in range(len(grid)):
            high = 0
            for j in range(len(grid[0])):
                high = max(high, grid[i][j])
            column_high.append(high)
        # ans
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                ans += min(row_high[i], column_high[j]) - grid[i][j]
        return ans


