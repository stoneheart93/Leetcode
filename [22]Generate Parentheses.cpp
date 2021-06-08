//Given n pairs of parentheses, write a function to generate all combinations of
// well-formed parentheses. 
//
// 
// Example 1: 
// Input: n = 3
//Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2: 
// Input: n = 1
//Output: ["()"]
// 
// 
// Constraints: 
//
// 
// 1 <= n <= 8 
// 
// Related Topics String Backtracking 
// 👍 8075 👎 338


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    void generateParenthesisUtil(int open, int close, string temp, vector<string>& result)
    {
        if(open > close)
            return;

        if(open == 0 && close == 0)
        {
            result.push_back(temp);
            return;
        }

        if(open > 0)
            generateParenthesisUtil(open - 1, close, temp + '(', result);
        if(close > 0)
            generateParenthesisUtil(open, close - 1, temp + ')', result);
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        generateParenthesisUtil(n, n, "", result);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
