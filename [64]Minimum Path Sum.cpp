//Given a m x n grid filled with non-negative numbers, find a path from top left
// to bottom right, which minimizes the sum of all numbers along its path. 
//
// Note: You can only move either down or right at any point in time. 
//
// 
// Example 1: 
//
// 
//Input: grid = [[1,3,1],
//               [1,5,1],
//               [4,2,1]]
//Output: 7
//Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// 
//
// Example 2: 
//
// 
//Input: grid = [[1,2,3],[4,5,6]]
//Output: 12
// 
//
// 
// Constraints: 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 200 
// 0 <= grid[i][j] <= 100 
// 
// Related Topics Array Dynamic Programming 
// 👍 4839 👎 87


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minPathSum(vector<vector<int>>& M)
    {
        int m = M.size();
        int n = M[0].size();

        for(int j = 1; j < n; j++)
            M[0][j] += M[0][j - 1];

        for(int i = 1; i < m; i++)
            M[i][0] += M[i - 1][0];

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                M[i][j] += min(M[i - 1][j], M[i][j - 1]);
            }
        }

        return M[m - 1][n - 1];
    }
};

//Time Complexity: O(mn)
//Space Complexity: O(mn)

//leetcode submit region end(Prohibit modification and deletion)
