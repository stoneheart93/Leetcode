//Given the head of a linked list, remove the nth node from the end of the list 
//and return its head. 
//
// Follow up: Could you do this in one pass? 
//
// 
// Example 1: 
//
// 
//Input: head = [1,2,3,4,5], n = 2
//Output: [1,2,3,5]
// 
//
// Example 2: 
//
// 
//Input: head = [1], n = 1
//Output: []
// 
//
// Example 3: 
//
// 
//Input: head = [1,2], n = 1
//Output: [1]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is sz. 
// 1 <= sz <= 30 
// 0 <= Node.val <= 100 
// 1 <= n <= sz 
// 
// Related Topics Linked List Two Pointers 
// 👍 5576 👎 314


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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        struct ListNode* slowptr = head;
        struct ListNode* fastptr = head;
        struct ListNode* prev = NULL;

        for(int i = 1; i <= n - 1 && fastptr != NULL; i++)
            fastptr = fastptr->next;

        while(fastptr->next != NULL)
        {
            prev = slowptr;
            slowptr = slowptr->next;
            fastptr = fastptr->next;
        }

        if(prev != NULL)
            prev->next = slowptr->next;
        else
            head = slowptr->next;

        delete slowptr;

        return head;
    }
};

//Time Complexity: O(len)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
