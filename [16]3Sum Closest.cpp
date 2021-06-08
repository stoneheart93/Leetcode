//Given an array nums of n integers and an integer target, find three integers i
//n nums such that the sum is closest to target. Return the sum of the three integ
//ers. You may assume that each input would have exactly one solution. 
//
// 
// Example 1: 
//
// 
//Input: nums = [-1,2,1,-4], target = 1
//Output: 2
//Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// 
//
// 
// Constraints: 
//
// 
// 3 <= nums.length <= 10^3 
// -10^3 <= nums[i] <= 10^3 
// -10^4 <= target <= 10^4 
// 
// Related Topics Array Two Pointers 
// 👍 3408 👎 178


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int threeSumClosest(vector<int>& a, int target)
    {
        int diff = INT_MAX;
        int result = -1;

        sort(a.begin(), a.end());
        int n = a.size();

        for(int i = 0; i < n - 2; i++)
        {
            int l = i + 1;
            int r = n - 1;

            while(l < r)
            {
                int curr_sum = a[i] + a[l] + a[r];

                if(abs(target - curr_sum) < diff)
                {
                    diff = abs(target - curr_sum);
                    result = curr_sum;
                }

                if(curr_sum < target)
                    l++;
                else
                    r--;
            }
        }

        return result;
    }
};

//Time Complexity: O(n^2)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
