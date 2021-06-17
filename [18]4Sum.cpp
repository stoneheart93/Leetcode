//Given an array nums of n integers, return an array of all the unique quadruple
//ts [nums[a], nums[b], nums[c], nums[d]] such that: 
//
// 
// 0 <= a, b, c, d < n 
// a, b, c, and d are distinct. 
// nums[a] + nums[b] + nums[c] + nums[d] == target 
// 
//
// You may return the answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,0,-1,0,-2,2], target = 0
//Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// 
//
// Example 2: 
//
// 
//Input: nums = [2,2,2,2,2], target = 8
//Output: [[2,2,2,2]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 200 
// -109 <= nums[i] <= 109 
// -109 <= target <= 109 
// 
// Related Topics Array Hash Table Two Pointers 
// 👍 3529 👎 429


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target)
    {
        vector<vector<int>> result;
        set<vector<int>> result_set;

        sort(a.begin(), a.end());
        int n = a.size();

        for(int i = 0; i < n - 3; i++)
        {
            for(int j = i + 1; j < n - 2; j++)
            {
                int l = j + 1;
                int r = n - 1;

                while(l < r)
                {
                    int curr_sum = a[i] + a[j] + a[l] + a[r];

                    if(curr_sum == target)
                    {
                        vector<int> temp = {a[i], a[j], a[l], a[r]};
                        result_set.insert(temp);

                        l++;
                        r--;
                    }
                    else if(curr_sum < target)
                        l++;
                    else
                        r--;
                }
            }
        }

        result.assign(result_set.begin(), result_set.end());
        return result;
    }
};

//Time Complexity: O(n^3)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
