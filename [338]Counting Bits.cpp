//Given an integer n, return an array ans of length n + 1 such that for each i (
//0 <= i <= n), ans[i] is the number of 1's in the binary representation of i. 
//
// 
// Example 1: 
//
// 
//Input: n = 2
//Output: [0,1,1]
//Explanation:
//0 --> 0
//1 --> 1
//2 --> 10
// 
//
// Example 2: 
//
// 
//Input: n = 5
//Output: [0,1,1,2,1,2]
//Explanation:
//0 --> 0
//1 --> 1
//2 --> 10
//3 --> 11
//4 --> 100
//5 --> 101
// 
//
// 
// Constraints: 
//
// 
// 0 <= n <= 105 
// 
//
// 
// Follow up: 
//
// 
// It is very easy to come up with a solution with a runtime of O(n log n). Can 
//you do it in linear time O(n) and possibly in a single pass? 
// Can you do it without using any built-in function (i.e., like __builtin_popco
//unt in C++)? 
// 
// Related Topics Dynamic Programming Bit Manipulation 
// 👍 4101 👎 218


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> DP(n + 1, 0);

        if(n >= 0)
            DP[0] = 0;
        if(n >= 1)
            DP[1] = 1;

        for(int i = 2; i <= n; i++)
        {
            if(i % 2 == 0)
                DP[i] = DP[i / 2];
            else
                DP[i] = 1 + DP[i - 1];
        }

        return DP;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
