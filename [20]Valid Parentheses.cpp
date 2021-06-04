//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']
//', determine if the input string is valid. 
//
// An input string is valid if: 
//
// 
// Open brackets must be closed by the same type of brackets. 
// Open brackets must be closed in the correct order. 
// 
//
// 
// Example 1: 
//
// 
//Input: s = "()"
//Output: true
// 
//
// Example 2: 
//
// 
//Input: s = "()[]{}"
//Output: true
// 
//
// Example 3: 
//
// 
//Input: s = "(]"
//Output: false
// 
//
// Example 4: 
//
// 
//Input: s = "([)]"
//Output: false
// 
//
// Example 5: 
//
// 
//Input: s = "{[]}"
//Output: true
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 104 
// s consists of parentheses only '()[]{}'. 
// 
// Related Topics String Stack 
// 👍 7664 👎 314


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    bool matching(char open, char close)
    {
        return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
    }

public:
    bool isValid(string str)
    {
        stack<char> s;
        for(int i = 0; str[i]; i++)
        {
            if(str[i] == '(' || str[i]  == '[' || str[i] == '{')
                s.push(str[i]);
            else if(str[i] == ')' || str[i]  == ']' || str[i] == '}')
            {
                if(s.empty())
                    return false;
                if(!matching(s.top(), str[i]))
                    return false;

                s.pop();
            }
        }

        return s.empty();
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
