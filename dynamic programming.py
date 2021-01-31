# class Solution:
#
#     def countPaths(self, grid, row, col):
#         if not self.validSqure(grid, row, col): return 0
#         if self.isAtEnd(grid, row, col): return 1
#         return self.countPaths(grid, row + 1, col) + self.countPaths(grid, row, col + 1)
#
#     def validSqure(self, grid, row, col):
#         return grid[row][col] == 0 if 0 <= row < len(grid) and 0 <= col < len(grid[0]) else False
#
#     def isAtEnd(self, grid, row, col):
#         return row == len(grid) - 1 and col == len(grid[0]) - 1

class Solution:

    def countPaths(self, grid):
        m, n = len(grid), len(grid[0])
        dp = [[0] * n for _ in range(m)]
        for i in range(n):
            dp[m - 1][i] = 1
        for i in range(m):
            dp[i][n - 1] = 1
        for i in range(m - 2, -1, -1):
            for j in range(n - 2, -1, -1):
                if grid[i][j] == 0:
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1]
                else:
                    dp[i][j] = 0
        return dp[0][0]


if __name__ == '__main__':
    sol = Solution()
    grid = [[0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 1, 0, 0, 0, 1, 0],
            [0, 0, 0, 0, 1, 0, 0, 0],
            [1, 0, 1, 0, 0, 1, 0, 0],
            [0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 1, 1, 0, 1, 0],
            [0, 1, 0, 0, 0, 1, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0]]
    # print(sol.countPaths(grid, 0, 0))
    print(sol.countPaths(grid))
