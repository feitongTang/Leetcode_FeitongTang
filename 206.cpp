/*
    link: https://leetcode.com/problems/reverse-linked-list/
*/

/*
    comment:
    met in bytedance
*/

/*
    status:
    Runtime: 39.74%
    Memory Usage: 97.28%
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
    ListNode *next;
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* temp1 = head;
        ListNode* temp2;
        head = temp1->next;
        temp1->next = nullptr;
        while (head) {
            temp2 = head->next;
            head->next = temp1;
            temp1 = head;
            head = temp2;
        }
        return temp1;
    }
};