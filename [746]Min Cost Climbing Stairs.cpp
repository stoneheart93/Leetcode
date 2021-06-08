//You are given an integer array cost where cost[i] is the cost of ith step on a
// staircase. Once you pay the cost, you can either climb one or two steps. 
//
// You can either start from the step with index 0, or the step with index 1. 
//
// Return the minimum cost to reach the top of the floor. 
//
// 
// Example 1: 
//
// 
//Input: cost = [10,15,20]
//Output: 15
//Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.
// 
//
// Example 2: 
//
// 
//Input: cost = [1,100,1,1,1,100,1,1,100,1]
//Output: 6
//Explanation: Cheapest is: start on cost[0], and only step on 1s, skipping cost
//[3].
// 
//
// 
// Constraints: 
//
// 
// 2 <= cost.length <= 1000 
// 0 <= cost[i] <= 999 
// 
// Related Topics Array Dynamic Programming 
// 👍 3289 👎 707


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        vector<int> DP(n + 2, 0);

        if(n >= 1)
            DP[1] = 0;
        if(n >= 2)
            DP[2] = 0;

        for(int i = 3; i <= n + 1; i++)
            DP[i] = min(DP[i - 2] + cost[i - 3], DP[i - 1] + cost[i - 2]);

        return DP[n + 1];
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
