//Given two strings s and t, return true if t is an anagram of s, and false othe
//rwise. 
//
// 
// Example 1: 
// Input: s = "anagram", t = "nagaram"
//Output: true
// Example 2: 
// Input: s = "rat", t = "car"
//Output: false
// 
// 
// Constraints: 
//
// 
// 1 <= s.length, t.length <= 5 * 104 
// s and t consist of lowercase English letters. 
// 
//
// 
// Follow up: What if the inputs contain Unicode characters? How would you adapt
// your solution to such a case? 
// Related Topics Hash Table Sort 
// 👍 2697 👎 165


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        vector<int> count(26, 0);

        int i;
        for(i = 0; i < s.size() && i < t.size(); i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        if(s[i] || t[i])
            return false;

        for(i = 0; i < 26; i++)
        {
            if(count[i])
                return false;
        }

        return true;
    }
};

//Time Complexity: O(min(m, n))
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
