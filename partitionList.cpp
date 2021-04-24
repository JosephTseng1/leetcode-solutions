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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *a = new ListNode, *b = new ListNode;
        ListNode *start = a, *end = b;
        while (head) {
            ListNode* newNode = new ListNode(head->val);
            if (head->val < x) {
                a->next = newNode;
                a = a->next;
            } else {
                b->next = newNode;
                b = b->next;
            }
            head = head->next;
        }
        a->next = end->next;
        return start->next;
    }
};
