//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k
//]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0. 
//
// Notice that the solution set must not contain duplicate triplets. 
//
// 
// Example 1: 
// Input: nums = [-1,0,1,2,-1,-4]
//Output: [[-1,-1,2],[-1,0,1]]
// Example 2: 
// Input: nums = []
//Output: []
// Example 3: 
// Input: nums = [0]
//Output: []
// 
// 
// Constraints: 
//
// 
// 0 <= nums.length <= 3000 
// -105 <= nums[i] <= 105 
// 
// Related Topics Array Two Pointers 
// 👍 10968 👎 1099


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a)
    {
        vector<vector<int>> result;

        sort(a.begin(), a.end());
        int n = a.size();

        for(int i = 0; i < n - 2; i++)
        {
            if(i != 0 && a[i] == a[i - 1])
                continue;

            int l = i + 1;
            int r = n - 1;

            while(l < r)
            {
                int curr_sum = a[i] + a[l] + a[r];

                if(curr_sum == 0)
                {
                    vector<int> temp = {a[i], a[l], a[r]};
                    result.push_back(temp);

                    while(l < r && a[l] == a[l + 1])
                        l++;
                    while(l < r && a[r] == a[r - 1])
                        r--;

                    l++;
                    r--;
                }
                else if(curr_sum < 0)
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
