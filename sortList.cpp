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
    ListNode* mergeLists(ListNode* left, ListNode* right) {
        ListNode * result = new ListNode;
        ListNode * answer = result;
        while (left && right) {
            if (left->val <= right->val) {
                result->next = left;
                left = left->next;
            } else {
                result->next = right;
                right = right->next;
            }
            result = result->next;
        }
        if (left) {
            result->next = left;
        }
        if (right) {
            result->next = right;
        }
        return answer->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* first = sortList(head);
        ListNode* second = sortList(slow);
        return mergeLists(first, second);
    }
};
