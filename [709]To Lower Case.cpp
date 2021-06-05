//Given a string s, return the string after replacing every uppercase letter wit
//h the same lowercase letter. 
//
// 
// Example 1: 
//
// 
//Input: s = "Hello"
//Output: "hello"
// 
//
// Example 2: 
//
// 
//Input: s = "here"
//Output: "here"
// 
//
// Example 3: 
//
// 
//Input: s = "LOVELY"
//Output: "lovely"
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 100 
// s consists of printable ASCII characters. 
// 
// Related Topics String 
// 👍 754 👎 2001


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string toLowerCase(string s)
    {
        string result = s;

        for(int i = 0; result[i]; i++)
        {
            if(result[i] >= 'A' && result[i] <= 'Z')
                result[i] = 'a' + (result[i] - 'A');
        }

        return result;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
