class Solution {
private:
    // Mapping from digits 0-9 to corresponding letters
    const vector<string> phoneMap = {
        "",     "",     "abc",  "def", 
        "ghi",  "jkl",  "mno",  "pqrs", 
        "tuv",  "wxyz"
    };

    void backtrack(int index, string& digits, string& current, vector<string>& result) {
        // Base case: if the current combination is complete
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get the letters corresponding to the current digit
        int digit = digits[index] - '0';
        string letters = phoneMap[digit];

        // Loop through all letters mapped to the current digit
        for (char c : letters) {
            current.push_back(c);              // Choose
            backtrack(index + 1, digits, current, result); // Explore
            current.pop_back();                // Backtrack (Unchoose)
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }

        string current = "";
        backtrack(0, digits, current, result);
        return result;
    }
};
