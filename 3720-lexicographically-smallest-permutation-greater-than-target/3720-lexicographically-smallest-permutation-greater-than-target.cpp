#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Changed the function name here to match LeetCode's system
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        
        // Count frequencies of each character in s
        vector<int> orig_counts(26, 0);
        for (char c : s) {
            orig_counts[c - 'a']++;
        }
        
        // Try every possible length of matching prefix from longest to shortest
        for (int i = n - 1; i >= 0; i--) {
            vector<int> counts = orig_counts;
            string prefix = "";
            bool valid_prefix = true;
            
            // 1. Try to construct the matching prefix target[0 ... i-1]
            for (int j = 0; j < i; j++) {
                int idx = target[j] - 'a';
                if (counts[idx] > 0) {
                    counts[idx]--;
                    prefix += target[j];
                } else {
                    valid_prefix = false;
                    break;
                }
            }
            
            if (!valid_prefix) continue;
            
            // 2. At position i, find the smallest available character strictly greater than target[i]
            char next_char = 0;
            for (int d = (target[i] - 'a') + 1; d < 26; d++) {
                if (counts[d] > 0) {
                    next_char = 'a' + d;
                    counts[d]--;
                    break;
                }
            }
            
            // 3. If we found a valid character for position i, fill the rest greedily
            if (next_char != 0) {
                string result = prefix + next_char;
                // Append all remaining characters in sorted order
                for (int d = 0; d < 26; d++) {
                    while (counts[d] > 0) {
                        result += ('a' + d);
                        counts[d]--;
                    }
                }
                return result;
            }
        }
        
        return "";
    }
};
