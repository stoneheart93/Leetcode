//Given an m x n binary matrix filled with 0's and 1's, find the largest square 
//containing only 1's and return its area. 
//
// 
// Example 1: 
//
// 
//Input: matrix = [["1","0","1","0","0"],
//                 ["1","0","1","1","1"],
//                 ["1","1","1","1","1"],
//                 ["1","0","0","1","0"]]
//Output: 4
// 
//
// Example 2: 
//
// 
//Input: matrix = [["0","1"],["1","0"]]
//Output: 1
// 
//
// Example 3: 
//
// 
//Input: matrix = [["0"]]
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 300 
// matrix[i][j] is '0' or '1'. 
// 
// Related Topics Dynamic Programming 
// 👍 4711 👎 109


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& M)
    {
        int m = M.size();
        int n = M[0].size();

        vector<vector<int>> DP(m, vector<int>(n, 0));

        DP[0][0] = M[0][0] - '0';

        for(int j = 1; j < n; j++)
            DP[0][j] = M[0][j] - '0';

        for(int i = 1; i < m; i++)
            DP[i][0] = M[i][0] - '0';

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(M[i][j] == '1')
                    DP[i][j] = min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1])) + 1;
            }
        }

        int max_area = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(DP[i][j] > max_area)
                    max_area = DP[i][j];
            }
        }

        return max_area * max_area;
    }
};

//Time Complexity: O(mn)
//Space Complexity: O(mn)

//leetcode submit region end(Prohibit modification and deletion)
