//Given the root of a binary tree, return the bottom-up level order traversal of
// its nodes' values. (i.e., from left to right, level by level from leaf to root)
//. 
//
// 
// Example 1: 
//
// 
//Input: root = [3,9,20,null,null,15,7]
//Output: [[15,7],[9,20],[3]]
// 
//
// Example 2: 
//
// 
//Input: root = [1]
//Output: [[1]]
// 
//
// Example 3: 
//
// 
//Input: root = []
//Output: []
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 2000]. 
// -1000 <= Node.val <= 1000 
// 
// Related Topics Tree Breadth-first Search 
// 👍 2223 👎 249


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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> result;
        if(root == NULL)
            return result;

        queue<struct TreeNode*> q;
        q.push(root);

        while(1)
        {
            int n = q.size();

            if(n == 0)
                break;

            vector<int> temp_vec;
            for(int i = 1; i <= n; i++)
            {
                struct TreeNode* temp = q.front();
                q.pop();

                temp_vec.push_back(temp->val);

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            result.push_back(temp_vec);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
