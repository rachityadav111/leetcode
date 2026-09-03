class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int mini = nums1[0];
        bool sameParity = true;

        for (int i = 1; i < nums1.size(); i++) {

            mini = min(mini, nums1[i]);

            if (nums1[i] % 2 != nums1[0] % 2) {
                sameParity = false;
            }
        }

        // Already all odd or all even
        if (sameParity) {
            return true;
        }

        // Mixed parity:
        // possible only if minimum element is odd
        return mini % 2 == 1;
    }
};