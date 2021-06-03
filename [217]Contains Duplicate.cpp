//Given an integer array nums, return true if any value appears at least twice i
//n the array, and return false if every element is distinct. 
//
// 
// Example 1: 
// Input: nums = [1,2,3,1]
//Output: true
// Example 2: 
// Input: nums = [1,2,3,4]
//Output: false
// Example 3: 
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
//Output: true
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 105 
// -109 <= nums[i] <= 109 
// 
// Related Topics Array Hash Table 
// 👍 1787 👎 851


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool containsDuplicate(vector<int>& a)
    {
        unordered_map<int, int> hash;

        for(int i = 0; i < a.size(); i++)
            hash[a[i]]++;

        for(auto it = hash.begin(); it != hash.end(); it++)
        {
            if(it->second > 1)
                return true;
        }

        return false;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
