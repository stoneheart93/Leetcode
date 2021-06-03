//Given an integer array nums where the elements are sorted in ascending order, 
//convert it to a height-balanced binary search tree. 
//
// A height-balanced binary tree is a binary tree in which the depth of the two 
//subtrees of every node never differs by more than one. 
//
// 
// Example 1: 
//
// 
//Input: nums = [-10,-3,0,5,9]
//Output: [0,-3,9,-10,null,5]
//Explanation: [0,-10,5,null,-3,null,9] is also accepted:
//
// 
//
// Example 2: 
//
// 
//Input: nums = [1,3]
//Output: [3,1]
//Explanation: [1,3] and [3,1] are both a height-balanced BSTs.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 104 
// -104 <= nums[i] <= 104 
// nums is sorted in a strictly increasing order. 
// 
// Related Topics Tree Depth-first Search 
// 👍 3996 👎 284


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    struct TreeNode* newNode(int data)
    {
        struct TreeNode* temp = new struct TreeNode;
        temp->val = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    struct TreeNode* sortedArrayToBSTUtil(const vector<int>& a, int start, int end)
    {
        if(start > end)
            return NULL;

        int mid = start + (end - start) / 2;
        struct TreeNode* root = newNode(a[mid]);
        root->left = sortedArrayToBSTUtil(a, start, mid - 1);
        root->right = sortedArrayToBSTUtil(a, mid + 1, end);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& a)
    {
        return sortedArrayToBSTUtil(a, 0, a.size() - 1);
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
