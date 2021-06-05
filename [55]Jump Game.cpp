//Given an array of non-negative integers nums, you are initially positioned at 
//the first index of the array. 
//
// Each element in the array represents your maximum jump length at that positio
//n. 
//
// Determine if you are able to reach the last index. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,3,1,1,4]
//Output: true
//Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// 
//
// Example 2: 
//
// 
//Input: nums = [3,2,1,0,4]
//Output: false
//Explanation: You will always arrive at index 3 no matter what. Its maximum jum
//p length is 0, which makes it impossible to reach the last index.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 104 
// 0 <= nums[i] <= 105 
// 
// Related Topics Array Greedy 
// 👍 6556 👎 431


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canJump(vector<int>& a)
    {
        if(a.size() == 1)
            return true;
        if(a[0] == 0)
            return false;

        int stairs = a[0];
        int ladder = a[0];
        int jump = 1;

        for(int i = 1; i < a.size(); i++)
        {
            if(i == a.size() - 1)
                return true;

            ladder = max(ladder, i + a[i]);
            stairs--;

            if(stairs == 0)
            {
                if(i == ladder)
                    return false;
                jump++;
                stairs = ladder - i;
            }
        }

        return false;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
