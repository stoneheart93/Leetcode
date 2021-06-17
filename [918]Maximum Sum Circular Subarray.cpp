//Given a circular integer array nums of length n, return the maximum possible s
//um of a non-empty subarray of nums. 
//
// A circular array means the end of the array connects to the beginning of the 
//array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previo
//us element of nums[i] is nums[(i - 1 + n) % n]. 
//
// A subarray may only include each element of the fixed buffer nums at most onc
//e. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not e
//xist i <= k1, k2 <= j with k1 % n == k2 % n. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,-2,3,-2]
//Output: 3
//Explanation: Subarray [3] has maximum sum 3
// 
//
// Example 2: 
//
// 
//Input: nums = [5,-3,5]
//Output: 10
//Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
// 
//
// Example 3: 
//
// 
//Input: nums = [3,-1,2,-1]
//Output: 4
//Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
// 
//
// Example 4: 
//
// 
//Input: nums = [3,-2,2,-3]
//Output: 3
//Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
// 
//
// Example 5: 
//
// 
//Input: nums = [-2,-3,-1]
//Output: -1
//Explanation: Subarray [-1] has maximum sum -1
// 
//
// 
// Constraints: 
//
// 
// n == nums.length 
// 1 <= n <= 3 * 104 
// -3 * 104 <= nums[i] <= 3 * 104 
// 
// Related Topics Array 
// 👍 1690 👎 78


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a)
    {
        int curr_sum = a[0];

        int curr_max = a[0];
        int curr_min = a[0];
        int max_so_far = a[0];
        int min_so_far = a[0];

        for(int i = 1; i < a.size(); i++)
        {
            curr_sum += a[i];

            curr_max = max(curr_max + a[i], a[i]);
            curr_min = min(curr_min + a[i], a[i]);

            max_so_far = max(max_so_far, curr_max);
            min_so_far = min(min_so_far, curr_min);
        }

        return curr_sum == min_so_far ? max_so_far : max(max_so_far, curr_sum - min_so_far);
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
