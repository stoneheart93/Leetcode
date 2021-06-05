//Given two strings s1 and s2, return true if s2 contains the permutation of s1.
// 
//
// In other words, one of s1's permutations is the substring of s2. 
//
// 
// Example 1: 
//
// 
//Input: s1 = "ab", s2 = "eidbaooo"
//Output: true
//Explanation: s2 contains one permutation of s1 ("ba").
// 
//
// Example 2: 
//
// 
//Input: s1 = "ab", s2 = "eidboaoo"
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= s1.length, s2.length <= 104 
// s1 and s2 consist of lowercase English letters. 
// 
// Related Topics Two Pointers Sliding Window 
// 👍 2504 👎 80


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> hash(26, 0);
        for(int i = 0; s1[i]; i++)
            hash[s1[i] - 'a']++;

        int len = s1.size();
        int begin = 0;
        for(int end = 0; s2[end] && len; end++)
        {
            if(hash[s2[end] - 'a'])
            {
                hash[s2[end] - 'a']--;
                len--;
            }
            else
            {
                while(begin < end)
                {
                    if(s2[begin] == s2[end])
                        break;
                    hash[s2[begin] - 'a']++;
                    len++;
                    begin++;
                }
                begin++;
            }
        }

        return !len;
    }
};

//Time Complexity: O(m + n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
