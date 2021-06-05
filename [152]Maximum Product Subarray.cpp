//Given an integer array nums, find a contiguous non-empty subarray within the a
//rray that has the largest product, and return the product. 
//
// It is guaranteed that the answer will fit in a 32-bit integer. 
//
// A subarray is a contiguous subsequence of the array. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,3,-2,4]
//Output: 6
//Explanation: [2,3] has the largest product 6.
// 
//
// Example 2: 
//
// 
//Input: nums = [-2,0,-1]
//Output: 0
//Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 2 * 104 
// -10 <= nums[i] <= 10 
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit 
//integer. 
// 
// Related Topics Array Dynamic Programming 
// 👍 7030 👎 230


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProduct(vector<int>& a)
    {
        int curr_max = a[0];
        int curr_min = a[0];
        int max_so_far = a[0];

        for(int i = 1; i < a.size(); i++)
        {
            if(a[i] < 0)
                swap(curr_max, curr_min);

            curr_max = max(curr_max * a[i], a[i]);
            curr_min = min(curr_min * a[i], a[i]);
            max_so_far = max(max_so_far, curr_max);
        }

        return max_so_far;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
