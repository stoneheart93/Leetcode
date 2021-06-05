//You are given an array of integers nums, there is a sliding window of size k w
//hich is moving from the very left of the array to the very right. You can only s
//ee the k numbers in the window. Each time the sliding window moves right by one 
//position. 
//
// Return the max sliding window. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
//Output: [3,3,5,5,6,7]
//Explanation: 
//Window position                Max
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
// Example 2: 
//
// 
//Input: nums = [1], k = 1
//Output: [1]
// 
//
// Example 3: 
//
// 
//Input: nums = [1,-1], k = 1
//Output: [1,-1]
// 
//
// Example 4: 
//
// 
//Input: nums = [9,11], k = 2
//Output: [11]
// 
//
// Example 5: 
//
// 
//Input: nums = [4,-2], k = 2
//Output: [4]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 105 
// -104 <= nums[i] <= 104 
// 1 <= k <= nums.length 
// 
// Related Topics Heap Sliding Window Dequeue 
// 👍 5980 👎 240


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k)
    {
        vector<int> result;
        deque<int> q;
        int end;
        for(end = 0; end < k; end++)
        {
            while(!q.empty() && a[end] >= a[q.back()])
                q.pop_back();
            q.push_back(end);
        }

        int begin = 0;
        for(; end < a.size(); end++)
        {
            result.push_back(a[q.front()]);

            if(begin == q.front())
                q.pop_front();

            while(!q.empty() && a[end] >= a[q.back()])
                q.pop_back();
            q.push_back(end);

            begin++;
        }

        result.push_back(a[q.front()]);

        return result;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(k)

//leetcode submit region end(Prohibit modification and deletion)
