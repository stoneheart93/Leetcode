//Given an m x n matrix, return all elements of the matrix in spiral order. 
//
// 
// Example 1: 
//
// 
//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,3,6,9,8,7,4,5]
// 
//
// Example 2: 
//
// 
//Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//Output: [1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
// Constraints: 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 10 
// -100 <= matrix[i][j] <= 100 
// 
// Related Topics Array 
// 👍 3987 👎 675


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& M)
    {
        vector<int> result;
        int m = M.size();
        int n = M[0].size();

        int k = 0, l = 0;
        while(k < m && l < n)
        {
            for(int j = l; j < n; j++)
                result.push_back(M[k][j]);
            k++;

            for(int i = k; i < m; i++)
                result.push_back(M[i][n - 1]);
            n--;

            if(k < m)
            {
                for(int j = n - 1; j >= l; j--)
                    result.push_back(M[m - 1][j]);
                m--;
            }

            if(l < n)
            {
                for(int i = m - 1; i >= k; i--)
                    result.push_back(M[i][l]);
                l++;
            }
        }

        return result;
    }
};

//Time Complexity: O(mn)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
