#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to calculate Greatest Common Divisor
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // Helper function to calculate Least Common Multiple safely
    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    // Counts how many valid coin amounts are <= max_val
    long long countAmounts(long long max_val, const vector<int>& coins) {
        long long count = 0;
        int n = coins.size();
        int totalSubsets = 1 << n; // 2^n subsets

        // Iterate through all non-empty subsets
        for (int mask = 1; mask < totalSubsets; ++mask) {
            long long currentLcm = 1;
            int elementsCount = 0;
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    elementsCount++;
                    currentLcm = lcm(currentLcm, coins[i]);
                    // If LCM exceeds max_val, it won't contribute to the count
                    if (currentLcm > max_val) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow) continue;

            // Inclusion-Exclusion formula
            if (elementsCount % 2 == 1) {
                count += max_val / currentLcm;
            } else {
                count -= max_val / currentLcm;
            }
        }
        return count;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // Sort and remove duplicates or multiples to minimize coins length if possible
        sort(coins.begin(), coins.end());
        vector<int> uniqueCoins;
        for (int coin : coins) {
            bool keep = true;
            for (int u : uniqueCoins) {
                if (coin % u == 0) {
                    keep = false; // It's a multiple of an existing smaller coin, redundant
                    break;
                }
            }
            if (keep) uniqueCoins.push_back(coin);
        }

        long long low = uniqueCoins.front();
        long long high = (long long)uniqueCoins.front() * k;
        long long ans = high;

        // Binary search for the exact value
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countAmounts(mid, uniqueCoins) >= k) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid amount
            } else {
                low = mid + 1;  // Increase the search range
            }
        }

        return ans;
    }
};

