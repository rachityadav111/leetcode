#include <string>
#include <cmath>

class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.length();
        int left_sum = 0, right_sum = 0;
        int left_q = 0, right_q = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                left_q++;
            } else {
                left_sum += num[i] - '0';
            }
        }
        
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                right_q++;
            } else {
                right_sum += num[i] - '0';
            }
        }
        int sum_diff = left_sum - right_sum;
        int q_diff = right_q - left_q; 
        if (sum_diff * 2 == q_diff * 9) {
            return false; // Bob wins
        }
        
        return true; // Alice wins
    }
};
