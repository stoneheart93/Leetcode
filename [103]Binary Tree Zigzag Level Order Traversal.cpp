//Given the root of a binary tree, return the zigzag level order traversal of it
//s nodes' values. (i.e., from left to right, then right to left for the next leve
//l and alternate between). 
//
// 
// Example 1: 
//
// 
//Input: root = [3,9,20,null,null,15,7]
//Output: [[3],[20,9],[15,7]]
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
// -100 <= Node.val <= 100 
// 
// Related Topics Stack Tree Breadth-first Search 
// 👍 3562 👎 130


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> result;

        if(root == NULL)
            return result;

        deque<struct TreeNode*> q;
        q.push_back(root);
        bool leftToRight = true;

        while(1)
        {
            int n = q.size();

            if(n == 0)
                break;

            vector<int> temp_vec;
            if(leftToRight)
            {
                for(int i = 1; i <= n; i++)
                {
                    struct TreeNode* temp = q.front();
                    q.pop_front();

                    temp_vec.push_back(temp->val);

                    if(temp->left)
                        q.push_back(temp->left);
                    if(temp->right)
                        q.push_back(temp->right);
                }
            }
            else
            {
                for(int i = 1; i <= n; i++)
                {
                    struct TreeNode* temp = q.back();
                    q.pop_back();

                    temp_vec.push_back(temp->val);

                    if(temp->right)
                        q.push_front(temp->right);
                    if(temp->left)
                        q.push_front(temp->left);

                }
            }
            result.push_back(temp_vec);
            leftToRight = !leftToRight;
        }

        return result;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//leetcode submit region end(Prohibit modification and deletion)
