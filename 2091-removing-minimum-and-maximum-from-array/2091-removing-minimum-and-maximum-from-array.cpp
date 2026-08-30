#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // If 1 or 2 elements, we must remove all of them

        // Find the indices of min and max elements
        int min_idx = 0;
        int max_idx = 0;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[min_idx]) {
                min_idx = i;
            }
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }
        
        // Ensure i is always the smaller index and j is the larger index
        int i = min(min_idx, max_idx);
        int j = max(min_idx, max_idx);
        
        // Calculate deletions for all 3 options
        int option1 = j + 1;               // Both from front
        int option2 = n - i;               // Both from back
        int option3 = (i + 1) + (n - j);   // One from front, one from back
        
        // Return the minimum of the three options
        return min({option1, option2, option3});
    }
};
