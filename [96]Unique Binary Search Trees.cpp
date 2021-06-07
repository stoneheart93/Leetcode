//Given an integer n, return the number of structurally unique BST's (binary sea
//rch trees) which has exactly n nodes of unique values from 1 to n. 
//
// 
// Example 1: 
//
// 
//Input: n = 3
//Output: 5
// 
//
// Example 2: 
//
// 
//Input: n = 1
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 19 
// 
// Related Topics Dynamic Programming Tree 
// 👍 4752 👎 176


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

    long int nCr(int n, int r)
    {
        long int result = 1;

        for(int i = 0; i < r; i++)
        {
            result *= (n - i);
            result /= (i + 1);
        }

        return result;
    }

    int factorial(int n)
    {
        int result = 1;

        for(int i = 1; i <= result; i++)
            result *= i;

        return result;
    }

public:
    int numTrees(int n)
    {
        //BST = 2nCn/(n + 1)
        //BT = BST * n!

        long int a = nCr(2 * n, n);
        long int b = n + 1;
        return a / b;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
