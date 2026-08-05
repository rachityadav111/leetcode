#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0;
        int high = m;
        
        while (low <= high) {
            int partitionX = low + (high - low) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;
            
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 1) {
                    return std::max(maxLeftX, maxLeftY);
                }
                return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
            }
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            }
            else {
                low = partitionX + 1;
            }
        }
        
        return 0.0;
    }
};
