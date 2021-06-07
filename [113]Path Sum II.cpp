//Given the root of a binary tree and an integer targetSum, return all root-to-l
//eaf paths where each path's sum equals targetSum. 
//
// A leaf is a node with no children. 
//
// 
// Example 1: 
//
// 
//Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//Output: [[5,4,11,2],[5,8,4,5]]
// 
//
// Example 2: 
//
// 
//Input: root = [1,2,3], targetSum = 5
//Output: []
// 
//
// Example 3: 
//
// 
//Input: root = [1,2], targetSum = 0
//Output: []
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
// 👍 2881 👎 84


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
    void pathSumUtil(struct TreeNode* root, int targetSum, int curr_sum, vector<int> path, vector<vector<int>>& path_vec)
    {
        if(root == NULL)
            return;

        curr_sum += root->val;
        path.push_back(root->val);

        if(root->left == NULL && root->right == NULL)
        {
            if(curr_sum == targetSum)
                path_vec.push_back(path);
            return;
        }

        pathSumUtil(root->left, targetSum, curr_sum, path, path_vec);
        pathSumUtil(root->right, targetSum, curr_sum, path, path_vec);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<vector<int>> path_vec;
        vector<int> path;
        pathSumUtil(root, targetSum, 0, path, path_vec);
        return path_vec;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
