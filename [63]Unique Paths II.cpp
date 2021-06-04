//A robot is located at the top-left corner of a m x n grid (marked 'Start' in t
//he diagram below). 
//
// The robot can only move either down or right at any point in time. The robot 
//is trying to reach the bottom-right corner of the grid (marked 'Finish' in the d
//iagram below). 
//
// Now consider if some obstacles are added to the grids. How many unique paths 
//would there be? 
//
// An obstacle and space is marked as 1 and 0 respectively in the grid. 
//
// 
// Example 1: 
//
// 
//Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
//Output: 2
//Explanation: There is one obstacle in the middle of the 3x3 grid above.
//There are two ways to reach the bottom-right corner:
//1. Right -> Right -> Down -> Down
//2. Down -> Down -> Right -> Right
// 
//
// Example 2: 
//
// 
//Input: obstacleGrid = [[0,1],[0,0]]
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// m == obstacleGrid.length 
// n == obstacleGrid[i].length 
// 1 <= m, n <= 100 
// obstacleGrid[i][j] is 0 or 1. 
// 
// Related Topics Array Dynamic Programming 
// 👍 2980 👎 302


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& M)
    {
        int m = M.size();
        int n = M[0].size();

        vector<vector<int>> DP(m, vector<int>(n, 0));

        if(M[0][0] == 1)
            return 0;

        DP[0][0] = 1;

        for(int j = 1; j < n; j++)
        {
            if(M[0][j] == 0)
                DP[0][j] = DP[0][j - 1];
        }

        for(int i = 1; i < m; i++)
        {
            if(M[i][0] == 0)
                DP[i][0] = DP[i - 1][0];
        }

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(M[i][j] == 0)
                    DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
            }
        }

        return DP[m - 1][n - 1];
    }
};

//Time Complexity: O(mn)
//Space Complexity: O(mn)

//leetcode submit region end(Prohibit modification and deletion)
