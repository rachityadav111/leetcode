#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:

    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> total_counts;
        for (int num : nums) {
            total_counts[num]++;
        }

        if (k == n) {
            int max_val = -1;
            for (int num : nums) {
                max_val = std::max(max_val, num);
            }
            return max_val;
        }

        if (k == 1) {
            int max_val = -1;
            for (auto& pair : total_counts) {
                if (pair.second == 1) {
                    max_val = std::max(max_val, pair.first);
                }
            }
            return max_val;
        }
        
        int ans = -1;
        if (total_counts[nums[0]] == 1) {
            ans = std::max(ans, nums[0]);
        }
        if (total_counts[nums[n - 1]] == 1) {
            ans = std::max(ans, nums[n - 1]);
        }

        return ans;
    }
};
