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
    // Function to detect the cycle in the linked list
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL) // If the list is empty, return NULL
            return NULL;
        
        ListNode* slow = head; // Initialize slow pointer
        ListNode* fast = head; // Initialize fast pointer
        
        // Detect if a cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next; // Move slow pointer by one step
            fast = fast->next->next; // Move fast pointer by two steps
            
            // If slow and fast pointers meet, a cycle is detected
            if (slow == fast) {
                slow = head; // Reset slow pointer to head
                while (slow != fast) { // Move both pointers until they meet
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Return the starting node of the cycle
            }
        }
        return NULL; // No cycle found, return NULL
    }
};