
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);

        dp[0] = 0;

        for (int j = 1; j <= n; j++) {
            for (int jump = 1; jump <= 3; jump++) {
                int i = j - jump;

                if (i >= 0) {
                    long long cost = costs[j - 1] + 1LL * jump * jump;

                    dp[j] = min(dp[j], dp[i] + cost);
                }
            }
        }

        return (int)dp[n];
    }
};
