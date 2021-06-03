//Given the head of a singly linked list, return true if it is a palindrome. 
//
// 
// Example 1: 
//
// 
//Input: head = [1,2,2,1]
//Output: true
// 
//
// Example 2: 
//
// 
//Input: head = [1,2]
//Output: false
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range [1, 105]. 
// 0 <= Node.val <= 9 
// 
//
// 
//Follow up: Could you do it in O(n) time and O(1) space? Related Topics Linked 
//List Two Pointers 
// 👍 5458 👎 442


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

    bool areIdentical(struct ListNode* a, struct ListNode* b)
    {
        if(a == NULL && b == NULL)
            return true;
        else if(a == NULL || b == NULL)
            return false;
        else
            return a->val == b->val && areIdentical(a->next, b->next);
    }

public:
    bool isPalindrome(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return true;

        struct ListNode* prev = NULL;
        struct ListNode* slowptr = head;
        struct ListNode* fastptr = head;

        while(fastptr != NULL && fastptr->next != NULL)
        {
            prev = slowptr;
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }

        struct ListNode* mid = NULL;
        if(fastptr != NULL)
        {
            mid = slowptr;
            slowptr = slowptr->next;
        }

        prev->next = NULL;
        struct ListNode* a = head;
        struct ListNode* b = slowptr;

        b = reverseList(b);
        bool result = areIdentical(a, b);
        b = reverseList(b);

        if(mid != NULL)
        {
            prev->next = mid;
            mid->next = b;
        }
        else
            prev->next = b;

        return result;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)

//leetcode submit region end(Prohibit modification and deletion)
