class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_seen(128, -1);
        
        int max_len = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char current_char = s[right];

            if (last_seen[current_char] >= left) {
                left = last_seen[current_char] + 1;
            }
            last_seen[current_char] = right;
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};
