# status definition
dp = [[0 for _ in range(m+1)] for _ in range(n+1)]

# initial status
dp[0][0] = x
dp[0][1] = y
...

# recurrence formula
for i in range(n+1):
    for j in range(m+1):
        ...
        d[i][j] = min(dp[i-1][j], dp[i][j-1], etc...)

# return optimal solution
return dp[m][n]
