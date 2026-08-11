class Solution {
public:
    string intToRoman(int num) {
        // Pairs of values and their corresponding Roman symbols in descending order
        vector<pair<int, string>> romanMapping = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };
        
        string result = "";
        
        // Loop through the mappings and subtract values from num
        for (const auto& mapping : romanMapping) {
            while (num >= mapping.first) {
                result += mapping.second;
                num -= mapping.first;
            }
        }
        
        return result;
    }
};
