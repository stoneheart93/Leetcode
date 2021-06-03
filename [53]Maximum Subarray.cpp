//Given an integer array nums, find the contiguous subarray (containing at least
// one number) which has the largest sum and return its sum. 
//
// 
// Example 1: 
//
// 
//Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
//Output: 6
//Explanation: [4,-1,2,1] has the largest sum = 6.
// 
//
// Example 2: 
//
// 
//Input: nums = [1]
//Output: 1
// 
//
// Example 3: 
//
// 
//Input: nums = [5,4,-1,7,8]
//Output: 23
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 3 * 104 
// -105 <= nums[i] <= 105 
// 
//
// 
//Follow up: If you have figured out the O(n) solution, try coding another solut
//ion using the divide and conquer approach, which is more subtle. Related Topics 
//Array Divide and Conquer Dynamic Programming 
// 👍 12242 👎 592


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubArray(vector<int>& a)
    {
        int curr_max = a[0];
        int max_so_far = a[0];

        for(int i = 1; i < a.size(); i++)
        {
            curr_max = max(curr_max + a[i], a[i]);
            max_so_far = max(max_so_far, curr_max);
        }

        return max_so_far;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
