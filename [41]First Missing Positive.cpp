//Given an unsorted integer array nums, find the smallest missing positive integ
//er. 
//
// You must implement an algorithm that runs in O(n) time and uses constant extr
//a space. 
//
// 
// Example 1: 
// Input: nums = [1,2,0]
//Output: 3
// Example 2: 
// Input: nums = [3,4,-1,1]
//Output: 2
// Example 3: 
// Input: nums = [7,8,9,11,12]
//Output: 1
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 5 * 105 
// -231 <= nums[i] <= 231 - 1 
// 
// Related Topics Array 
// 👍 5946 👎 1021


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int firstMissingPositive(vector<int>& a)
    {
        int n = a.size();
        for(int i = 0; i < n; i++)
        {
            if(a[i] <= 0 || a[i] > n)
                continue;

            int val = a[i];
            while(val != a[val - 1])
            {
                int next_val = a[val - 1];
                a[val - 1] = val;
                val = next_val;

                if(val <= 0 || val > n)
                    break;
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(a[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
