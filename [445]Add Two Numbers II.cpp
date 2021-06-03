//You are given two non-empty linked lists representing two non-negative integer
//s. The most significant digit comes first and each of their nodes contains a sin
//gle digit. Add the two numbers and return the sum as a linked list. 
//
// You may assume the two numbers do not contain any leading zero, except the nu
//mber 0 itself. 
//
// 
// Example 1: 
//
// 
//Input: l1 = [7,2,4,3], l2 = [5,6,4]
//Output: [7,8,0,7]
// 
//
// Example 2: 
//
// 
//Input: l1 = [2,4,3], l2 = [5,6,4]
//Output: [8,0,7]
// 
//
// Example 3: 
//
// 
//Input: l1 = [0], l2 = [0]
//Output: [0]
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
//
// 
// Follow up: Could you solve it without reversing the input lists? 
// Related Topics Linked List 
// 👍 2421 👎 201


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
    struct ListNode* reverseList(struct ListNode* head)
    {
        struct ListNode* rider = head;
        struct ListNode* r_next = NULL;
        struct ListNode* prev = NULL;

        while(rider != NULL)
        {
            r_next = rider->next;
            rider->next = prev;
            prev = rider;
            rider = r_next;
        }

        return prev;
    }

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
        a = reverseList(a);
        b = reverseList(b);

        struct ListNode* result = NULL;
        int carry = 0;
        while(a != NULL || b != NULL)
        {
            int sum = (a ? a->val : 0) + (b ? b->val : 0) + carry;

            struct ListNode* temp = newNode(sum % 10);
            carry = sum / 10;

            temp->next = result;
            result = temp;

            a = a ? a->next : NULL;
            b = b ? b->next : NULL;
        }

        if(carry)
        {
            struct ListNode* temp = newNode(carry);
            temp->next = result;
            result = temp;
        }

        return result;
    }
};

//Time Complexity: O(m + n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
