//Given an integer array nums and an integer k, return the k most frequent eleme
//nts. You may return the answer in any order. 
//
// 
// Example 1: 
// Input: nums = [1,1,1,2,2,3], k = 2
//Output: [1,2]
// Example 2: 
// Input: nums = [1], k = 1
//Output: [1]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 105 
// k is in the range [1, the number of unique elements in the array]. 
// It is guaranteed that the answer is unique. 
// 
//
// 
// Follow up: Your algorithm's time complexity must be better than O(n log n), w
//here n is the array's size. 
// Related Topics Hash Table Heap 
// 👍 5143 👎 274


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    void swap(pair<int, int>& a, pair<int, int>& b)
    {
        pair<int, int> temp = a;
        a = b;
        b = temp;
    }

    int partition(vector<pair<int, int>>& a, int low, int high)
    {
        pair<int, int> pivot = a[high];
        int i = low - 1;
        for(int j = low; j <= high - 1; j++)
        {
            if(a[j].second > pivot.second)
            {
                i++;
                swap(a[i], a[j]);
            }
        }
        i++;
        swap(a[i], a[high]);
        return i;
    }

    int random_partition(vector<pair<int, int>>& a, int low, int high)
    {
        int n = high - low + 1;
        srand(time(NULL));
        int pivot = rand() % n;
        swap(a[low + pivot], a[high]);
        return partition(a, low, high);
    }

    int quick_select(vector<pair<int, int>>& a, int low, int high, int k)
    {
        if(low == high && low == k - 1)
            return low;
        if(low < high)
        {
            int p = random_partition(a, low, high);
            if(p == k - 1)
                return p;
            else if(p < k - 1)
                return quick_select(a, p + 1, high, k);
            else
                return quick_select(a, low, p - 1, k);
        }

        return -1;
    }

public:
    vector<int> topKFrequent(vector<int>& a, int k)
    {
        unordered_map<int, int> hash;
        for(int i = 0; i < a.size(); i++)
            hash[a[i]]++;

        vector<pair<int, int>> a_vec;
        for(auto it = hash.begin(); it != hash.end(); it++)
            a_vec.push_back({it->first, it->second});

        quick_select(a_vec, 0, a_vec.size() - 1, k);

        vector<int> result;
        for(int i = 0; i < k; i++)
            result.push_back(a_vec[i].first);
        return result;
    }
};

//Time Complexity: O(m) -> avg, O(m^2) -> worst, where m is the no of distinct elements in a
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
