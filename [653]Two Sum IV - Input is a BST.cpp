//Given the root of a Binary Search Tree and a target number k, return true if t
//here exist two elements in the BST such that their sum is equal to the given tar
//get. 
//
// 
// Example 1: 
//
// 
//Input: root = [5,3,6,2,4,null,7], k = 9
//Output: true
// 
//
// Example 2: 
//
// 
//Input: root = [5,3,6,2,4,null,7], k = 28
//Output: false
// 
//
// Example 3: 
//
// 
//Input: root = [2,1,3], k = 4
//Output: true
// 
//
// Example 4: 
//
// 
//Input: root = [2,1,3], k = 1
//Output: false
// 
//
// Example 5: 
//
// 
//Input: root = [2,1,3], k = 3
//Output: true
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 104]. 
// -104 <= Node.val <= 104 
// root is guaranteed to be a valid binary search tree. 
// -105 <= k <= 105 
// 
// Related Topics Tree 
// 👍 2141 👎 156


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
    bool findTargetUtil(struct TreeNode* root, int targetSum, unordered_set<int>& hash)
    {
        if(root == NULL)
            return false;

        if(hash.find(targetSum - root->val) != hash.end())
            return true;
        else
            hash.insert(root->val);

        return findTargetUtil(root->left, targetSum, hash) || findTargetUtil(root->right, targetSum, hash);
    }

public:
    bool findTarget(TreeNode* root, int targetSum)
    {
        unordered_set<int> hash;
        return findTargetUtil(root, targetSum, hash);
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
