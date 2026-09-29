class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int len = m + n - 1;

        // Valid parentheses string must have even length
        if (len % 2 != 0)
            return false;

        // First character must be '('
        if (grid[0][0] == ')')
            return false;

        // Last character must be ')'
        if (grid[m - 1][n - 1] == '(')
            return false;

        // dp[i][j][balance]
        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(n, vector<bool>(len + 1, false))
        );

        // Starting cell
        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Starting cell already initialized
                if (i == 0 && j == 0)
                    continue;

                for (int balance = 0; balance <= len; balance++) {

                    bool possible = false;

                    // Can come from top
                    if (i > 0 && dp[i - 1][j][balance]) {
                        possible = true;
                    }

                    // Can come from left
                    if (j > 0 && dp[i][j - 1][balance]) {
                        possible = true;
                    }

                    if (!possible)
                        continue;

                    int newBalance;

                    if (grid[i][j] == '(')
                        newBalance = balance + 1;
                    else
                        newBalance = balance - 1;

                    // Balance can never be negative
                    if (newBalance < 0)
                        continue;

                    dp[i][j][newBalance] = true;
                }
            }
        }

        // At the end, balance must be exactly 0
        return dp[m - 1][n - 1][0];
    }
};