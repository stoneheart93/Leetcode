//You are given a perfect binary tree where all leaves are on the same level, an
//d every parent has two children. The binary tree has the following definition: 
//
// 
//struct Node {
//  int val;
//  Node *left;
//  Node *right;
//  Node *next;
//}
// 
//
// Populate each next pointer to point to its next right node. If there is no ne
//xt right node, the next pointer should be set to NULL. 
//
// Initially, all next pointers are set to NULL. 
//
// 
//
// Follow up: 
//
// 
// You may only use constant extra space. 
// Recursive approach is fine, you may assume implicit stack space does not coun
//t as extra space for this problem. 
// 
//
// 
// Example 1: 
//
// 
//
// 
//Input: root = [1,2,3,4,5,6,7]
//Output: [1,#,2,3,#,4,5,6,7,#]
//Explanation: Given the above perfect binary tree (Figure A), your function sho
//uld populate each next pointer to point to its next right node, just like in Fig
//ure B. The serialized output is in level order as connected by the next pointers
//, with '#' signifying the end of each level.
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the given tree is less than 4096. 
// -1000 <= node.val <= 1000 
// Related Topics Tree Depth-first Search Breadth-first Search 
// 👍 3515 👎 170


//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root)
    {
        if(root == NULL)
            return NULL;

        if(root->left)
            root->left->next = root->right;
        if(root->right && root->next)
            root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);
        return root;
    }

    /*Node* connect(Node* root)
    {
        if(root == NULL)
            return NULL;

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            if(temp != NULL)
            {
                temp->next = q.front();

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            else
            {
                if(!q.empty())
                    q.push(NULL);
            }
        }

        return root;
    }*/
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
