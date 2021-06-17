//Given an array of integers nums, sort the array in increasing order based on t
//he frequency of the values. If multiple values have the same frequency, sort the
//m in decreasing order. 
//
// Return the sorted array. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,1,2,2,2,3]
//Output: [3,1,1,2,2,2]
//Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a
// frequency of 3.
// 
//
// Example 2: 
//
// 
//Input: nums = [2,3,1,3,2]
//Output: [1,3,3,2,2]
//Explanation: '2' and '3' both have a frequency of 2, so they are sorted in dec
//reasing order.
// 
//
// Example 3: 
//
// 
//Input: nums = [-1,1,-6,4,5,-6,1,4,1]
//Output: [5,-1,4,4,-6,-6,1,1,1] 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 100 
// -100 <= nums[i] <= 100 
// 
// Related Topics Array Sort 
// 👍 548 👎 30


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static bool compare(pair<int, int>& a, pair<int, int>& b)
    {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
public:
    vector<int> frequencySort(vector<int>& a)
    {
        unordered_map<int, int> hash;
        for(int i = 0; i < a.size(); i++)
            hash[a[i]]++;

        vector<pair<int, int>> array_count;
        for(auto it = hash.begin(); it != hash.end(); it++)
            array_count.push_back({it->first, it->second});

        sort(array_count.begin(), array_count.end(), compare);

        vector<int> result;
        for(int i = 0; i < array_count.size(); i++)
        {
            while(array_count[i].second--)
                result.push_back(array_count[i].first);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
