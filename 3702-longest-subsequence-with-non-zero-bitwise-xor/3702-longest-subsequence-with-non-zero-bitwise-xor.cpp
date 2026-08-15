class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXOR = 0;
        bool hasNonZero = false;
        
        for (int num : nums) {
            totalXOR ^= num;
            if (num > 0) {
                hasNonZero = true;
            }
        }
        if (totalXOR != 0) {
            return nums.size();
        }
        if (hasNonZero) {
            return nums.size() - 1;
        }
        
        return 0;
    }
};
