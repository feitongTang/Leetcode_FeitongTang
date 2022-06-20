/*
    link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
*/

/*
    comment:
    an easy linked lisk problem
    the performance is not good enough
*/

/*
    status:
    Runtime: 13.49%
    Memory Usage: 8.01%
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

struct ListNode
{
    int val;
    ListNode* next;
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }
        int temp = head->val;
        ListNode* ptr = head;
        while (ptr->next) {
            if (ptr->next->val == temp) {
                ptr->next = ptr->next->next;
            } else {
                ptr = ptr->next;
                temp = ptr->val;
            }
        }
        return head;
    }
};