//Given two integer arrays nums1 and nums2, return an array of their intersectio
//n. Each element in the result must appear as many times as it shows in both arra
//ys and you may return the result in any order. 
//
// 
// Example 1: 
//
// 
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2,2]
// 
//
// Example 2: 
//
// 
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [4,9]
//Explanation: [9,4] is also accepted.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums1.length, nums2.length <= 1000 
// 0 <= nums1[i], nums2[i] <= 1000 
// 
//
// 
// Follow up: 
//
// 
// What if the given array is already sorted? How would you optimize your algori
//thm? 
// What if nums1's size is small compared to nums2's size? Which algorithm is be
//tter? 
// What if elements of nums2 are stored on disk, and the memory is limited such 
//that you cannot load all elements into the memory at once? 
// 
// Related Topics Hash Table Two Pointers Binary Search Sort 
// 👍 2328 👎 530


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b)
    {
        unordered_map<int, int> hash;
        for(int i = 0; i < a.size(); i++)
            hash[a[i]]++;

        vector<int> result;
        for(int i = 0; i < b.size(); i++)
        {
            if(hash[b[i]])
            {
                result.push_back(b[i]);
                hash[b[i]]--;
            }
        }

        return result;
    }
};

//Time Complexity: O(m + n)
//Space Complexity: O(m)

//leetcode submit region end(Prohibit modification and deletion)
