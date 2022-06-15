/*
    link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

/*
    comment:
    the relative position between two pointers is important
*/

/*
    status:
    Runtime: 89.37%
    Memory Usage: 74.96%
*/

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

struct ListNode;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        for (int i = 0; i < n; ++i) {
            ptr2 = ptr2-> next;
        }
        
        if (!ptr2) {
            ListNode * temp = head;
            head = temp->next;
            delete temp;
            return head;
        }
        
        while (ptr2->next) {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }

        ListNode *temp = ptr1->next;
        ptr1->next = temp->next;
        delete temp;
        
        return head;
    }
};