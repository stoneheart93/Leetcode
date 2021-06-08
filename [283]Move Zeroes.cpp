//Given an integer array nums, move all 0's to the end of it while maintaining t
//he relative order of the non-zero elements. 
//
// Note that you must do this in-place without making a copy of the array. 
//
// 
// Example 1: 
// Input: nums = [0,1,0,3,12]
//Output: [1,3,12,0,0]
// Example 2: 
// Input: nums = [0]
//Output: [0]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 104 
// -231 <= nums[i] <= 231 - 1 
// 
//
// 
//Follow up: Could you minimize the total number of operations done? Related Top
//ics Array Two Pointers 
// 👍 5718 👎 174


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void moveZeroes(vector<int>& a)
    {
        int j = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != 0)
                a[j++] = a[i];
        }

        while(j < a.size())
            a[j++] = 0;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
