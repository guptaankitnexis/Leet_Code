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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Initialize fast pointer
        ListNode* fast = head;
        // Move fast pointer n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        // If fast reached the end, remove the head
        if(fast == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        // Initialize slow pointer
        ListNode* slow = head;
        // Move fast to the end, maintaining the gap
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        // Remove the nth node from the end
        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNode;
        // Return the modified list
        return head;
    }
};