//Given the root of a binary tree, return the sum of values of its deepest leave
//s.
// 
// Example 1: 
//
// 
//Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
//Output: 15
// 
//
// Example 2: 
//
// 
//Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
//Output: 19
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 104]. 
// 1 <= Node.val <= 100 
// 
// Related Topics Tree Depth-first Search 
// 👍 1487 👎 59


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
    int deepestLeavesSum(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        queue<struct TreeNode*> q;
        q.push(root);
        int sum;

        while(1)
        {
            int n = q.size();

            if(n == 0)
                break;

            sum = 0;
            for(int i = 1; i <= n; i++)
            {
                struct TreeNode* temp = q.front();
                q.pop();

                sum += temp->val;

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }

        return sum;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
