//Write a function that reverses a string. The input string is given as an array
// of characters s. 
//
// 
// Example 1: 
// Input: s = ["h","e","l","l","o"]
//Output: ["o","l","l","e","h"]
// Example 2: 
// Input: s = ["H","a","n","n","a","h"]
//Output: ["h","a","n","n","a","H"]
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 105 
// s[i] is a printable ascii character. 
// 
//
// 
// Follow up: Do not allocate extra space for another array. You must do this by
// modifying the input array in-place with O(1) extra memory. 
// Related Topics Two Pointers String 
// 👍 2467 👎 782


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    void reverseStringUtil(vector<char>& s, int start, int end)
    {
        while(start < end)
        {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }

public:
    void reverseString(vector<char>& s)
    {
        reverseStringUtil(s, 0, s.size() - 1);
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
