//Given an array nums of non-negative integers, return an array consisting of al
//l the even elements of nums, followed by all the odd elements of nums. 
//
// You may return any answer array that satisfies this condition. 
//
// 
//
// 
// Example 1: 
//
// 
//Input: nums = [3,1,2,4]
//Output: [2,4,3,1]
//The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
// 
//
// 
//
// Note: 
//
// 
// 1 <= nums.length <= 5000 
// 0 <= nums[i] <= 5000 
// 
// 
// Related Topics Array 
// 👍 1781 👎 96


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    vector<int> sortArrayByParity(vector<int>& a)
    {
        int i = -1;
        for(int j = 0; j < a.size(); j++)
        {
            if(a[j] % 2 == 0)
            {
                i++;
                swap(a[i], a[j]);
            }
        }

        return a;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
