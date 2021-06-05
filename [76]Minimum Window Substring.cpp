//Given two strings s and t of lengths m and n respectively, return the minimum 
//window substring of s such that every character in t (including duplicates) is i
//ncluded in the window. If there is no such substring, return the empty string ""
//. 
//
// The testcases will be generated such that the answer is unique. 
//
// A substring is a contiguous sequence of characters within the string. 
//
// 
// Example 1: 
//
// 
//Input: s = "ADOBECODEBANC", t = "ABC"
//Output: "BANC"
//Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' fr
//om string t.
// 
//
// Example 2: 
//
// 
//Input: s = "a", t = "a"
//Output: "a"
//Explanation: The entire string s is the minimum window.
// 
//
// Example 3: 
//
// 
//Input: s = "a", t = "aa"
//Output: ""
//Explanation: Both 'a's from t must be included in the window.
//Since the largest window of s only has one 'a', return empty string.
// 
//
// 
// Constraints: 
//
// 
// m == s.length 
// n == t.length 
// 1 <= m, n <= 105 
// s and t consist of uppercase and lowercase English letters. 
// 
//
// 
//Follow up: Could you find an algorithm that runs in O(m + n) time? Related Top
//ics Hash Table Two Pointers String Sliding Window 
// 👍 6789 👎 461


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t)
    {
        int sLen = s.size(), tLen = t.size();
        if(tLen > sLen)
            return "";

        vector<int> needToFind(256, 0);
        vector<int> hasFound(256, 0);

        for(int i = 0; i < tLen; i++)
            needToFind[t[i]]++;

        int minWindow = INT_MAX, minBegin, minEnd;
        int count = 0;
        int begin = 0, end;
        for(end = 0; end < sLen; end++)
        {
            if(needToFind[s[end]] == 0)
                continue;

            hasFound[s[end]]++;

            if(hasFound[s[end]] <= needToFind[s[end]])
                count++;

            if(count == tLen)
            {
                while(needToFind[s[begin]] == 0 || hasFound[s[begin]] > needToFind[s[begin]])
                {
                    if(hasFound[s[begin]] > needToFind[s[begin]])
                        hasFound[s[begin]]--;
                    begin++;
                }

                int window = end - begin + 1;
                if(window < minWindow)
                {
                    minWindow = window;
                    minBegin = begin;
                    minEnd = end;
                }
            }
        }


        string result = "";

        if(minWindow != INT_MAX)
        {
            for(int i = minBegin; i <= minEnd; i++)
                result += s[i];
        }
        return result;
    }
};

//Time Complexity: O(m + n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
