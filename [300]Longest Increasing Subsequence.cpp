//Given an integer array nums, return the length of the longest strictly increas
//ing subsequence. 
//
// A subsequence is a sequence that can be derived from an array by deleting som
//e or no elements without changing the order of the remaining elements. For examp
//le, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7]. 
//
// 
// Example 1: 
//
// 
//Input: nums = [10,9,2,5,3,7,101,18]
//Output: 4
//Explanation: The longest increasing subsequence is [2,3,7,101], therefore the 
//length is 4.
// 
//
// Example 2: 
//
// 
//Input: nums = [0,1,0,3,2,3]
//Output: 4
// 
//
// Example 3: 
//
// 
//Input: nums = [7,7,7,7,7,7,7]
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 2500 
// -104 <= nums[i] <= 104 
// 
//
// 
// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time co
//mplexity? 
// Related Topics Binary Search Dynamic Programming 
// 👍 7413 👎 162


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
public:
    int lengthOfLIS(vector<int>& a)
    {
        int n = a.size();
        vector<int> DP(n, INT_MAX);
        int max_len = 0;

        for(int i = 0; i < n; i++)
        {
            auto it = lower_bound(DP.begin(), DP.end(), a[i]);
            *it = a[i];
            max_len = max(max_len, (it - DP.begin() + 1));
        }

        return max_len;
    }
};

//Time Complexity: O(n log n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
