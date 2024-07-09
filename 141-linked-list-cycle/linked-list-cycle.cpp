/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        // Initialize two pointers, both starting at the head of the list
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the list with the two pointers
        while (fast != NULL && fast->next != NULL) {
            // Move the slow pointer one step
            slow = slow->next;
            // Move the fast pointer two steps
            fast = fast->next->next;

            // If slow and fast pointers meet, a cycle is detected
            if (slow == fast) {
                return true;
            }
        }

        // If we reach here, no cycle was detected
        return false;
    }
};