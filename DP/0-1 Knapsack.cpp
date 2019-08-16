int n, w;
int weights[MAXN], values[MAXN];
int dp[MAXN][MAXW];

int Knapsack() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (weights[i] <= j) dp[i][j] = max(values[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][w];
}
