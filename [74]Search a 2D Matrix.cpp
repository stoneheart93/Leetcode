//Write an efficient algorithm that searches for a value in an m x n matrix. Thi
//s matrix has the following properties: 
//
// 
// Integers in each row are sorted from left to right. 
// The first integer of each row is greater than the last integer of the previou
//s row. 
// 
//
// 
// Example 1: 
//
// 
//Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//Output: true
// 
//
// Example 2: 
//
// 
//Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
//Output: false
// 
//
// 
// Constraints: 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 100 
// -104 <= matrix[i][j], target <= 104 
// 
// Related Topics Array Binary Search 
// 👍 3433 👎 201


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& M, int target)
    {
        int m = M.size();
        int n = M[0].size();

        int i = 0, j = n - 1;
        while(i < m && j >= 0)
        {
            if(M[i][j] == target)
                return true;
            else if(target < M[i][j])
                j--;
            else
                i++;
        }

        return false;
    }
};

//Time Complexity: O(m + n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
