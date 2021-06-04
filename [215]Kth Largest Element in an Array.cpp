//Given an integer array nums and an integer k, return the kth largest element i
//n the array. 
//
// Note that it is the kth largest element in the sorted order, not the kth dist
//inct element. 
//
// 
// Example 1: 
// Input: nums = [3,2,1,5,6,4], k = 2
//Output: 5
// Example 2: 
// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
//Output: 4
// 
// 
// Constraints: 
//
// 
// 1 <= k <= nums.length <= 104 
// -104 <= nums[i] <= 104 
// 
// Related Topics Divide and Conquer Heap 
// 👍 5827 👎 368


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int partition(vector<int>& a, int low, int high)
    {
        int pivot = a[high];
        int i = low - 1;
        for(int j = low; j < high; j++)
        {
            if(a[j] > pivot)
            {
                i++;
                swap(a[i], a[j]);
            }
        }
        i++;
        swap(a[i], a[high]);
        return i;
    }

    int random_partition(vector<int>& a, int low, int high)
    {
        int n = high - low + 1;
        srand(time(NULL));
        int pivot = rand() % n;
        swap(a[high], a[low + pivot]);
        return partition(a, low, high);
    }

    int quick_select(vector<int>& a, int low, int high, int k)
    {
        if(low == high && low == k - 1)
            return a[low];
        else
        {
            int p = random_partition(a, low, high);
            if(p == k - 1)
                return a[p];
            else if(p < k - 1)
                return quick_select(a, p + 1, high, k);
            else
                return quick_select(a, low, p - 1, k);
        }

        return -1;
    }
public:
    int findKthLargest(vector<int>& a, int k)
    {
        return quick_select(a, 0, a.size() - 1, k);
    }
};

//Time Complexity: O(n) - Avg case
//Time Complexity: O(n^2) - Worst case
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
