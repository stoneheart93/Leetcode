//You are given two non-empty linked lists representing two non-negative integer
//s. The digits are stored in reverse order, and each of their nodes contains a si
//ngle digit. Add the two numbers and return the sum as a linked list. 
//
// You may assume the two numbers do not contain any leading zero, except the nu
//mber 0 itself. 
//
// 
// Example 1: 
//
// 
//Input: l1 = [2,4,3], l2 = [5,6,4]
//Output: [7,0,8]
//Explanation: 342 + 465 = 807.
// 
//
// Example 2: 
//
// 
//Input: l1 = [0], l2 = [0]
//Output: [0]
// 
//
// Example 3: 
//
// 
//Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//Output: [8,9,9,9,0,0,0,1]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in each linked list is in the range [1, 100]. 
// 0 <= Node.val <= 9 
// It is guaranteed that the list represents a number that does not have leading
// zeros. 
// 
// Related Topics Linked List Math Recursion 
// 👍 12017 👎 2819


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
struct ListNode* newNode(int data)
    {
        struct ListNode* temp = new struct ListNode;
        temp->val = data;
        temp->next = NULL;
        return temp;
    }

public:
    ListNode* addTwoNumbers(ListNode* a, ListNode* b)
    {
        struct ListNode* result = NULL;
        struct ListNode* prev = NULL;

        int carry = 0;
        while(a != NULL || b != NULL)
        {
            int sum = (a ? a->val : 0) + (b ? b->val : 0) + carry;

            struct ListNode* temp = newNode(sum % 10);
            carry = sum / 10;

            if(result == NULL)
                result = temp;
            else
                prev->next = temp;

            prev = temp;

            a = a ? a->next : NULL;
            b = b ? b->next : NULL;
        }

        if(carry)
            prev->next = newNode(carry);

        return result;
    }
};

//Time Complexity: O(max(m, n))
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
