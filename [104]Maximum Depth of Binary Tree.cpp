//Given the root of a binary tree, return its maximum depth. 
//
// A binary tree's maximum depth is the number of nodes along the longest path f
//rom the root node down to the farthest leaf node. 
//
// 
// Example 1: 
//
// 
//Input: root = [3,9,20,null,null,15,7]
//Output: 3
// 
//
// Example 2: 
//
// 
//Input: root = [1,null,2]
//Output: 2
// 
//
// Example 3: 
//
// 
//Input: root = []
//Output: 0
// 
//
// Example 4: 
//
// 
//Input: root = [0]
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 104]. 
// -100 <= Node.val <= 100 
// Related Topics Tree Depth-first Search Recursion 
// 👍 4078 👎 97


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
public:
    int maxDepth(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
