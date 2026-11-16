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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) 
            return head;
        
        ListNode *newHead = head->next;
        ListNode *prev = head;
        
        while (head->next) {
            ListNode *temp = head->next->next;

            prev->next = head->next;
            head->next->next = head;
            head->next = temp;

            if (!temp)
                break;

            prev = head;
            head = head->next;
        }

        return newHead;
    }
};