#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Map row number to a bitmask of reserved seats (bits 1 to 10)
        unordered_map<int, int> reservedRows;
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            reservedRows[row] |= (1 << col);
        }

        // Each completely empty row contributes 2 groups
        int ans = (n - reservedRows.size()) * 2;

        // Bitmasks for the 3 blocks:
        // Left: seats 2, 3, 4, 5
        const int leftMask   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        // Right: seats 6, 7, 8, 9
        const int rightMask  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
        // Middle: seats 4, 5, 6, 7
        const int middleMask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);

        for (const auto& [row, mask] : reservedRows) {
            bool leftPossible   = (mask & leftMask) == 0;
            bool rightPossible  = (mask & rightMask) == 0;
            bool middlePossible = (mask & middleMask) == 0;

            if (leftPossible && rightPossible) {
                ans += 2;
            } else if (leftPossible || rightPossible || middlePossible) {
                ans += 1;
            }
        }

        return ans;
    }
};
