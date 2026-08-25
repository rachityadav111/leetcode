#include <vector>
#include <unordered_set>

class Solution {
public:
    int missingMultiple(std::vector<int>& nums, int k) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int current_multiple = k;
        while (numSet.count(current_multiple)) {
            current_multiple += k;
        }
        return current_multiple;
    }
};
