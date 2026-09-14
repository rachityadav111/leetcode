class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Check if rec2 is completely outside rec1 (left, right, below, or above)
        return !(rec2[2] <= rec1[0] || // rec2 is to the left of rec1
                 rec2[0] >= rec1[2] || // rec2 is to the right of rec1
                 rec2[3] <= rec1[1] || // rec2 is below rec1
                 rec2[1] >= rec1[3]);  // rec2 is above rec1
    }
};
