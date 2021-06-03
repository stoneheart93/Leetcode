//Given an array of integers nums and an integer target, return indices of the t
//wo numbers such that they add up to target. 
//
// You may assume that each input would have exactly one solution, and you may n
//ot use the same element twice. 
//
// You can return the answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,7,11,15], target = 9
//Output: [0,1]
//Output: Because nums[0] + nums[1] == 9, we return [0, 1].
// 
//
// Example 2: 
//
// 
//Input: nums = [3,2,4], target = 6
//Output: [1,2]
// 
//
// Example 3: 
//
// 
//Input: nums = [3,3], target = 6
//Output: [0,1]
// 
//
// 
// Constraints: 
//
// 
// 2 <= nums.length <= 104 
// -109 <= nums[i] <= 109 
// -109 <= target <= 109 
// Only one valid answer exists. 
// 
//
// 
//Follow-up: Can you come up with an algorithm that is less than O(n2) time comp
//lexity? Related Topics Array Hash Table 
// 👍 21372 👎 735


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int sum)
    {
        vector<int> result;

        unordered_map<int, int> hash;
        for(int i = 0; i < a.size(); i++)
        {
            if(hash.find(sum - a[i]) != hash.end())
            {
                result.push_back(i);
                result.push_back(hash[sum - a[i]]);
                return result;
            }
            else
                hash[a[i]] = i;
        }

        return result;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
