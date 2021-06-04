//Given the root of a binary tree, return all root-to-leaf paths in any order. 
//
// A leaf is a node with no children. 
//
// 
// Example 1: 
//
// 
//Input: root = [1,2,3,null,5]
//Output: ["1->2->5","1->3"]
// 
//
// Example 2: 
//
// 
//Input: root = [1]
//Output: ["1"]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 100]. 
// -100 <= Node.val <= 100 
// 
// Related Topics Tree Depth-first Search 
// 👍 2646 👎 139


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
    void binaryTreePathsUtil(TreeNode* root, string path, vector<string>& pathVec)
    {
        if(root == NULL)
            return;

        if(root->left == NULL && root->right == NULL)
        {
            path += to_string(root->val);
            pathVec.push_back(path);
            return;
        }
        else
            path += to_string(root->val) + "->";

        binaryTreePathsUtil(root->left, path, pathVec);
        binaryTreePathsUtil(root->right, path, pathVec);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> pathVec;
        binaryTreePathsUtil(root, "", pathVec);
        return pathVec;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
