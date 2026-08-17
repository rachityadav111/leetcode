#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    int memo[501][501];
    vector<int> prefSum;
    int getSum(int i, int j) {
        return prefSum[j + 1] - prefSum[i];
    }

    int solve(int i, int j, const vector<int>& stoneValue) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int maxScore = 0;
        for (int k = i; k < j; ++k) {
            int leftSum = getSum(i, k);
            int rightSum = getSum(k + 1, j);

            if (leftSum < rightSum) {
                maxScore = max(maxScore, leftSum + solve(i, k, stoneValue));
            } 
            else if (leftSum > rightSum) {
                maxScore = max(maxScore, rightSum + solve(k + 1, j, stoneValue));
            } 
            else {
                int chooseLeft = leftSum + solve(i, k, stoneValue);
                int chooseRight = rightSum + solve(k + 1, j, stoneValue);
                maxScore = max({maxScore, chooseLeft, chooseRight});
            }
        }

        return memo[i][j] = maxScore;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                memo[i][j] = -1;
            }
        }
        prefSum.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefSum[i + 1] = prefSum[i] + stoneValue[i];
        }

        return solve(0, n - 1, stoneValue);
    }
};
