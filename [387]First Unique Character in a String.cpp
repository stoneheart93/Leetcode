//Given a string s, return the first non-repeating character in it and return it
//s index. If it does not exist, return -1. 
//
// 
// Example 1: 
// Input: s = "leetcode"
//Output: 0
// Example 2: 
// Input: s = "loveleetcode"
//Output: 2
// Example 3: 
// Input: s = "aabb"
//Output: -1
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 105 
// s consists of only lowercase English letters. 
// 
// Related Topics Hash Table String 
// 👍 3044 👎 147


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int firstUniqChar(string s)
    {
        vector<int> count(26, 0);

        for(int i = 0; s[i]; i++)
            count[s[i] - 'a']++;

        for(int i = 0; s[i]; i++)
        {
            if(count[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
