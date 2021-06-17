//Given a string containing digits from 2-9 inclusive, return all possible lette
//r combinations that the number could represent. Return the answer in any order.
//
//
// A mapping of digit to letters (just like on the telephone buttons) is given b
//elow. Note that 1 does not map to any letters.
//
//
//
//
// Example 1:
//
//
//Input: digits = "23"
//Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//
//
// Example 2:
//
//
//Input: digits = ""
//Output: []
//
//
// Example 3:
//
//
//Input: digits = "2"
//Output: ["a","b","c"]
//
//
//
// Constraints:
//
//
// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].
//
// Related Topics String Backtracking Depth-first Search Recursion
// 👍 6346 👎 535


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void letterCombinationsUtil(string digits, int index, string letters, vector<string>& result)
    {
        if(index == digits.size())
            result.push_back(letters);
        else
        {
            int digit = digits[index] - '0';
            for(int i = 0; i < keypad[digit].size(); i++)
                letterCombinationsUtil(digits, index + 1, letters + keypad[digit][i], result);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;

        if(digits.size() != 0)
            letterCombinationsUtil(digits, 0, "", result);

        return result;
    }
};

//Time Complexity: O(k^n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
