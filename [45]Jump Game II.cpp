//Given an array of non-negative integers nums, you are initially positioned at 
//the first index of the array. 
//
// Each element in the array represents your maximum jump length at that positio
//n. 
//
// Your goal is to reach the last index in the minimum number of jumps. 
//
// You can assume that you can always reach the last index. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,3,1,1,4]
//Output: 2
//Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 
//step from index 0 to 1, then 3 steps to the last index.
// 
//
// Example 2: 
//
// 
//Input: nums = [2,3,0,1,4]
//Output: 2
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 104 
// 0 <= nums[i] <= 1000 
// 
// Related Topics Array Greedy 
// 👍 4543 👎 194


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int jump(vector<int>& a)
    {
        if(a.size() == 1)
            return 0;
        if(a[0] == 0)
            return -1;

        int ladder = a[0];
        int stairs = a[0];
        int jump = 1;

        for(int i = 1; i < a.size(); i++)
        {
            if(i == a.size() - 1)
                return jump;

            ladder = max(ladder, i + a[i]);
            stairs--;

            if(stairs == 0)
            {
                if(i == ladder)
                    return -1;
                jump++;
                stairs = ladder - i;
            }
        }

        return -1;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
