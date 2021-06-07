//Given an array of points where points[i] = [xi, yi] represents a point on the 
//X-Y plane and an integer k, return the k closest points to the origin (0, 0). 
//
// The distance between two points on the X-Y plane is the Euclidean distance (i
//.e., √(x1 - x2)2 + (y1 - y2)2). 
//
// You may return the answer in any order. The answer is guaranteed to be unique
// (except for the order that it is in). 
//
// 
// Example 1: 
//
// 
//Input: points = [[1,3],[-2,2]], k = 1
//Output: [[-2,2]]
//Explanation:
//The distance between (1, 3) and the origin is sqrt(10).
//The distance between (-2, 2) and the origin is sqrt(8).
//Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
//We only want the closest k = 1 points from the origin, so the answer is just [
//[-2,2]].
// 
//
// Example 2: 
//
// 
//Input: points = [[3,3],[5,-1],[-2,4]], k = 2
//Output: [[3,3],[-2,4]]
//Explanation: The answer [[-2,4],[3,3]] would also be accepted.
// 
//
// 
// Constraints: 
//
// 
// 1 <= k <= points.length <= 104 
// -104 < xi, yi < 104 
// 
// Related Topics Divide and Conquer Heap Sort 
// 👍 3167 👎 163


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

    void swap(vector<int>& a, vector<int>& b)
    {
        vector<int> temp = a;
        a = b;
        b = temp;
    }

    int dist(vector<int>& a)
    {
        return (a[0] * a[0]) + (a[1] * a[1]);
    }

    int partition(vector<vector<int>>& a, int low, int high)
    {
        vector<int> pivot = a[high];
        int i = low - 1;
        for(int j = low; j <= high - 1; j++)
        {
            if(dist(a[j]) <= dist(pivot))
            {
                i++;
                swap(a[i], a[j]);
            }
        }
        i++;
        swap(a[i], a[high]);
        return i;
    }

    int random_partition(vector<vector<int>>& a, int low, int high)
    {
        int n = high - low + 1;
        srand(time(NULL));
        int pivot = rand() % n;
        swap(a[low + pivot], a[high]);
        return partition(a, low, high);
    }

    int quick_select(vector<vector<int>>& a, int low, int high, int k)
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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        quick_select(points, 0, points.size() - 1, k);

        vector<vector<int>> result;
        for(int i = 0; i < k; i++)
            result.push_back(points[i]);
        return result;
    }
};

//Time Complexity: O(n) -> avg, O(n^2) -> worst
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
