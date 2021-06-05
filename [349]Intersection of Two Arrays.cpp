//Given two integer arrays nums1 and nums2, return an array of their intersectio
//n. Each element in the result must be unique and you may return the result in an
//y order. 
//
// 
// Example 1: 
//
// 
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2]
// 
//
// Example 2: 
//
// 
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [9,4]
//Explanation: [4,9] is also accepted.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums1.length, nums2.length <= 1000 
// 0 <= nums1[i], nums2[i] <= 1000 
// 
// Related Topics Hash Table Two Pointers Binary Search Sort 
// 👍 1468 👎 1579


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b)
    {
        unordered_set<int> hash;
        for(int i = 0; i < a.size(); i++)
            hash.insert(a[i]);

        vector<int> result;
        for(int i = 0; i < b.size(); i++)
        {
            if(hash.find(b[i]) != hash.end())
            {
                result.push_back(b[i]);
                hash.erase(b[i]);
            }
        }

        return result;
    }
};

//Time Complexity: O(m + n)
//Space Complexity: O(m)

//leetcode submit region end(Prohibit modification and deletion)
