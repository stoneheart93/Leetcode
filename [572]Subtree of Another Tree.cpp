//Given the roots of two binary trees root and subRoot, return true if there is 
//a subtree of root with the same structure and node values of subRoot and false o
//therwise. 
//
// A subtree of a binary tree tree is a tree that consists of a node in tree and
// all of this node's descendants. The tree tree could also be considered as a sub
//tree of itself. 
//
// 
// Example 1: 
//
// 
//Input: root = [3,4,5,1,2], subRoot = [4,1,2]
//Output: true
// 
//
// Example 2: 
//
// 
//Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
//Output: false
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the root tree is in the range [1, 2000]. 
// The number of nodes in the subRoot tree is in the range [1, 1000]. 
// -104 <= root.val <= 104 
// -104 <= subRoot.val <= 104 
// 
// Related Topics Tree 
// 👍 3531 👎 175


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
    bool areIdentical(struct TreeNode* a, struct TreeNode* b)
    {
        if(a == NULL && b == NULL)
            return true;
        if(a == NULL || b == NULL)
            return false;
        return a->val == b->val && areIdentical(a->left, b->left) && areIdentical(a->right, b->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL)
            return false;
        if(subRoot == NULL)
            return true;
        if(areIdentical(root, subRoot))
            return true;
        else
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

//Time Complexity:O(mn)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
