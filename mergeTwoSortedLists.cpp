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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* mergedList = new ListNode(0);
        ListNode* result = mergedList;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                mergedList->next = l1;
                l1 = l1->next;
            } else {
                mergedList->next = l2;
                l2 = l2->next;
            }
            mergedList = mergedList->next;
        }
        if (l1) {
            mergedList->next = l1;
        }
        if (l2) {
            mergedList->next = l2;
        }
        return result->next;
    }
};
