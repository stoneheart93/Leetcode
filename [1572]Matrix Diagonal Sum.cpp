//Given a square matrix mat, return the sum of the matrix diagonals. 
//
// Only include the sum of all the elements on the primary diagonal and all the 
//elements on the secondary diagonal that are not part of the primary diagonal. 
//
// 
// Example 1: 
//
// 
//Input: mat = [[1,2,3],
//              [4,5,6],
//              [7,8,9]]
//Output: 25
//Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
//Notice that element mat[1][1] = 5 is counted only once.
// 
//
// Example 2: 
//
// 
//Input: mat = [[1,1,1,1],
//              [1,1,1,1],
//              [1,1,1,1],
//              [1,1,1,1]]
//Output: 8
// 
//
// Example 3: 
//
// 
//Input: mat = [[5]]
//Output: 5
// 
//
// 
// Constraints: 
//
// 
// n == mat.length == mat[i].length 
// 1 <= n <= 100 
// 1 <= mat[i][j] <= 100 
// 
// Related Topics Array 
// 👍 535 👎 10


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int diagonalSum(vector<vector<int>>& M)
    {
        int n = M.size();
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    sum += M[i][j];
                else if(i + j == n - 1)
                    sum += M[i][j];
            }
        }

        return sum;
    }
};

//Time Complexity: O(n^2)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
