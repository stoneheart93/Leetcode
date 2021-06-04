//Given two integer arrays preorder and inorder where preorder is the preorder t
//raversal of a binary tree and inorder is the inorder traversal of the same tree,
// construct and return the binary tree. 
//
// 
// Example 1: 
//
// 
//Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//Output: [3,9,20,null,null,15,7]
// 
//
// Example 2: 
//
// 
//Input: preorder = [-1], inorder = [-1]
//Output: [-1]
// 
//
// 
// Constraints: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// preorder and inorder consist of unique values. 
// Each value of inorder also appears in preorder. 
// preorder is guaranteed to be the preorder traversal of the tree. 
// inorder is guaranteed to be the inorder traversal of the tree. 
// 
// Related Topics Array Tree Depth-first Search 
// 👍 5390 👎 133


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

    struct TreeNode* newNode(int data)
    {
        struct TreeNode* temp = new struct TreeNode;
        temp->val = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    struct TreeNode* buildTreeUtil(vector<int>& preorder, int preS, int preE, vector<int>& inorder, int inS, int inE)
    {
        if(inS > inE)
            return NULL;

        int rootData = preorder[preS];
        int inRootIndex = -1;
        for(int i = inS; i <= inE; i++)
        {
            if(inorder[i] == rootData)
            {
                inRootIndex = i;
                break;
            }
        }

        int lInS = inS;
        int lInE = inRootIndex - 1;
        int rInS = inRootIndex + 1;
        int rInE = inE;

        int lPreS = preS + 1;
        int lPreE = lPreS + (lInE - lInS);
        int rPreS = lPreE + 1;
        int rPreE = preE;

        struct TreeNode* root = newNode(rootData);
        root->left = buildTreeUtil(preorder, lPreS, lPreE, inorder, lInS, lInE);
        root->right = buildTreeUtil(preorder, rPreS, rPreE, inorder, rInS, rInE);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return buildTreeUtil(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};

//Time Complexity: O(n^2)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
