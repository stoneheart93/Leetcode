//You are climbing a staircase. It takes n steps to reach the top. 
//
// Each time you can either climb 1 or 2 steps. In how many distinct ways can yo
//u climb to the top? 
//
// 
// Example 1: 
//
// 
//Input: n = 2
//Output: 2
//Explanation: There are two ways to climb to the top.
//1. 1 step + 1 step
//2. 2 steps
// 
//
// Example 2: 
//
// 
//Input: n = 3
//Output: 3
//Explanation: There are three ways to climb to the top.
//1. 1 step + 1 step + 1 step
//2. 1 step + 2 steps
//3. 2 steps + 1 step
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 45 
// 
// Related Topics Dynamic Programming 
// 👍 6812 👎 214


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int climbStairs(int n)
    {
        vector<int> DP(n + 1, 0);

        if(n >= 1)
            DP[1] = 1;
        if(n >= 2)
            DP[2] = 2;

        for(int i = 3; i <= n; i++)
        {
            DP[i] = DP[i - 2] + DP[i - 1];
        }

        return DP[n];
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
