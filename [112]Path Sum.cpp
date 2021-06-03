//Given the root of a binary tree and an integer targetSum, return true if the t
//ree has a root-to-leaf path such that adding up all the values along the path eq
//uals targetSum. 
//
// A leaf is a node with no children. 
//
// 
// Example 1: 
//
// 
//Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
//Output: true
// 
//
// Example 2: 
//
// 
//Input: root = [1,2,3], targetSum = 5
//Output: false
// 
//
// Example 3: 
//
// 
//Input: root = [1,2], targetSum = 0
//Output: false
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 5000]. 
// -1000 <= Node.val <= 1000 
// -1000 <= targetSum <= 1000 
// 
// Related Topics Tree Depth-first Search 
// 👍 3239 👎 622


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
    bool hasPathSumUtil(struct TreeNode* root, int targetSum, int preSum)
    {
        if(root == NULL)
            return false;

        preSum += root->val;

        if(root->left == NULL && root->right == NULL)
            return (preSum == targetSum);

        return hasPathSumUtil(root->left, targetSum, preSum) || hasPathSumUtil(root->right, targetSum, preSum);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        return hasPathSumUtil(root, targetSum, 0);
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
