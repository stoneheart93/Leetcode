//Given the root of a binary tree and an integer targetSum, return the number of
// paths where the sum of the values along the path equals targetSum. 
//
// The path does not need to start or end at the root or a leaf, but it must go 
//downwards (i.e., traveling only from parent nodes to child nodes). 
//
// 
// Example 1: 
//
// 
//Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
//Output: 3
//Explanation: The paths that sum to 8 are shown.
// 
//
// Example 2: 
//
// 
//Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//Output: 3
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 1000]. 
// -109 <= Node.val <= 109 
// -1000 <= targetSum <= 1000 
// 
// Related Topics Tree 
// 👍 5260 👎 324


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
    void pathSumUtil(struct TreeNode* root, int targetSum, int& result, unordered_map<int, int>& hash, int preSum)
    {
        if(root == NULL)
            return;

        preSum += root->val;

        result += hash[preSum - targetSum];
        hash[preSum]++;

        pathSumUtil(root->left, targetSum, result, hash, preSum);
        pathSumUtil(root->right, targetSum, result, hash, preSum);

        hash[preSum]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum)
    {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int result = 0;
        pathSumUtil(root, targetSum, result, hash, 0);
        return result;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
