//Given two strings word1 and word2, return the minimum number of operations req
//uired to convert word1 to word2. 
//
// You have the following three operations permitted on a word: 
//
// 
// Insert a character 
// Delete a character 
// Replace a character 
// 
//
// 
// Example 1: 
//
// 
//Input: word1 = "horse", word2 = "ros"
//Output: 3
//Explanation: 
//horse -> rorse (replace 'h' with 'r')
//rorse -> rose (remove 'r')
//rose -> ros (remove 'e')
// 
//
// Example 2: 
//
// 
//Input: word1 = "intention", word2 = "execution"
//Output: 5
//Explanation: 
//intention -> inention (remove 't')
//inention -> enention (replace 'i' with 'e')
//enention -> exention (replace 'n' with 'x')
//exention -> exection (replace 'n' with 'c')
//exection -> execution (insert 'u')
// 
//
// 
// Constraints: 
//
// 
// 0 <= word1.length, word2.length <= 500 
// word1 and word2 consist of lowercase English letters. 
// 
// Related Topics String Dynamic Programming 
// 👍 5752 👎 67


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> DP(m + 1, vector<int>(n + 1, 0));

        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i == 0)
                    DP[i][j] = j;
                else if(j == 0)
                    DP[i][j] = i;
                else if(word1[i - 1] == word2[j - 1])
                    DP[i][j] = DP[i - 1][j - 1];
                else
                    DP[i][j] = 1 + min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1]));
            }
        }

        return DP[m][n];
    }
};

//Time Complexity: O(mn)
//Space Complexity: O(mn)

//leetcode submit region end(Prohibit modification and deletion)
