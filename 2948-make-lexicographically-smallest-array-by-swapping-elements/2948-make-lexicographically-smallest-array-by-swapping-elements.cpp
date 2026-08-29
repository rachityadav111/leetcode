#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
public:
    // Fixed the function name here to match LeetCode's expectations
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Step 1: Create a sorted copy of nums to find connected components
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        // Group tracking
        int groupNum = 0;
        unordered_map<int, int> numToGroup;
        unordered_map<int, list<int>> groupToList;
        
        // Initialize the first element in the first group
        numToGroup[sortedNums[0]] = groupNum;
        groupToList[groupNum].push_back(sortedNums[0]);
        
        // Step 2: Distribute elements into groups based on the limit
        for (int i = 1; i < n; i++) {
            if (sortedNums[i] - sortedNums[i - 1] > limit) {
                groupNum++; // Start a new group if the gap is too large
            }
            numToGroup[sortedNums[i]] = groupNum;
            groupToList[groupNum].push_back(sortedNums[i]);
        }
        
        // Step 3: Rebuild the result array using the original order of positions
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int currNum = nums[i];
            int group = numToGroup[currNum];
            
            // Pop the smallest remaining element from this group
            result[i] = groupToList[group].front();
            groupToList[group].pop_front();
        }
        
        return result;
    }
};
