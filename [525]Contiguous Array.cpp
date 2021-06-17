//Given a binary array nums, return the maximum length of a contiguous subarray 
//with an equal number of 0 and 1. 
//
// 
// Example 1: 
//
// 
//Input: nums = [0,1]
//Output: 2
//Explanation: [0, 1] is the longest contiguous subarray with an equal number of
// 0 and 1.
// 
//
// Example 2: 
//
// 
//Input: nums = [0,1,0]
//Output: 2
//Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal nu
//mber of 0 and 1.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 105 
// nums[i] is either 0 or 1. 
// 
// Related Topics Hash Table 
// 👍 2903 👎 146


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMaxLength(vector<int>& a)
    {
        unordered_map<int, int> hash;
        int sum = 0;
        int max_len = 0;

        for(int i = 0; i < a.size(); i++)
        {
            sum += (a[i] == 0) ? -1 : 1;

            if(sum == 0)
                max_len = i + 1;

            if(hash.find(sum) != hash.end())
                max_len = max(max_len, i - hash[sum]);
            else
                hash[sum] = i;
        }

        return max_len;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
