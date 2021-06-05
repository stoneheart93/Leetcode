//Given a string s, find the length of the longest substring without repeating
//characters.
//
// 
// Example 1: 
//
// 
//Input: s = "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
// 
//
// Example 2: 
//
// 
//Input: s = "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
// 
//
// Example 3: 
//
// 
//Input: s = "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Notice that the answer must be a substring, "pwke" is a subsequence and not a 
//substring.
// 
//
// Example 4: 
//
// 
//Input: s = ""
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// 0 <= s.length <= 5 * 104 
// s consists of English letters, digits, symbols and spaces. 
// 
// Related Topics Hash Table Two Pointers String Sliding Window 
// 👍 14783 👎 755


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> hash;

        int max_len = 0;
        int begin = 0;
        for(int end = 0; s[end]; end++)
        {
            if(hash.find(s[end]) == hash.end())
            {
                hash.insert(s[end]);
                max_len = max(max_len, hash.size());
            }
            else
            {
                while(begin < end)
                {
                    if(s[begin] == s[end])
                    {
                        begin++;
                        break;
                    }
                    hash.erase(s[begin]);
                    begin++;
                }
            }
        }

        return max_len;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
