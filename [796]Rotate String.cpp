//We are given two strings, s and goal. 
//
// A shift on s consists of taking string s and moving the leftmost character to
// the rightmost position. For example, if s = 'abcde', then it will be 'bcdea' af
//ter one shift on s. Return true if and only if s can become goal after some numb
//er of shifts on s. 
//
// 
//Example 1:
//Input: s = 'abcde', goal = 'cdeab'
//Output: true
//
//Example 2:
//Input: s = 'abcde', goal = 'abced'
//Output: false
// 
//
// Note: 
//
// 
// s and goal will have length at most 100. 
// 
// 👍 1137 👎 67


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    void computeLPS(string pattern, vector<int>& LPS)
    {
        int n = pattern.size();
        LPS[0] = 0;
        int i = 1, j = 0;

        while(i < n)
        {
            if(pattern[i] == pattern[j])
            {
                LPS[i] = j + 1;
                i++;
                j++;
            }
            else
            {
                if(j == 0)
                {
                    LPS[i] = 0;
                    i++;
                }
                else
                    j = LPS[j - 1];
            }
        }
    }

    bool KMPmatch(string text, string pattern)
    {
        int m = text.size();
        int n = pattern.size();

        vector<int> LPS(n, 0);
        computeLPS(pattern, LPS);

        int i = 0, j = 0;
        while(i < m)
        {
            if(text[i] == pattern[j])
            {
                i++;
                j++;
                if(j == n)
                    return true;
            }
            else
            {
                if(j == 0)
                    i++;
                else
                    j = LPS[j - 1];
            }
        }

        return false;
    }

public:
    bool rotateString(string s, string goal)
    {
        if(s.size() != goal.size())
            return false;
        if(s.size() == 0)
            return true;
        return KMPmatch(s + s, goal);
    }
};

//Time Complexity: O(2m)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
