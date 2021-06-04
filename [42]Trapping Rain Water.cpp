//Given n non-negative integers representing an elevation map where the width of
// each bar is 1, compute how much water it can trap after raining. 
//
// 
// Example 1: 
//
// 
//Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
//Output: 6
//Explanation: The above elevation map (black section) is represented by array [
//0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are
// being trapped.
// 
//
// Example 2: 
//
// 
//Input: height = [4,2,0,3,2,5]
//Output: 9
// 
//
// 
// Constraints: 
//
// 
// n == height.length 
// 0 <= n <= 3 * 104 
// 0 <= height[i] <= 105 
// 
// Related Topics Array Two Pointers Dynamic Programming Stack 
// 👍 11624 👎 170


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int>& a)
    {
        int n = a.size();
        if(n == 0)
            return 0;

        int LMax[n];
        LMax[0] = a[0];
        for(int i = 1; i < n; i++)
            LMax[i] = max(LMax[i - 1], a[i]);

        int RMax[n];
        RMax[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--)
            RMax[i] = max(RMax[i + 1], a[i]);

        int water = 0;
        for(int i = 0; i < n; i++)
            water += min(LMax[i], RMax[i]) - a[i];

        return water;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
