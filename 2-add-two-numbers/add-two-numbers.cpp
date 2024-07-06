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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0; // Initialize carry to 0
        ListNode* p1 = l1; // Pointer for the first list
        ListNode* p2 = l2; // Pointer for the second list
        ListNode* dummyHead = new ListNode(-1); // Dummy node to simplify handling head
        ListNode* current = dummyHead; // Pointer to build the new list
        
        // Traverse both lists
        while (p1 != nullptr || p2 != nullptr) {
            int sum = carry; // Start with the carry
            if (p1) {
                sum += p1->val; // Add value from first list
                p1 = p1->next; // Move to the next node
            }
            if (p2) {
                sum += p2->val; // Add value from second list
                p2 = p2->next; // Move to the next node
            }
            ListNode* newNode = new ListNode(sum % 10); // Create new node with the digit part of the sum
            current->next = newNode; // Link new node to the result list
            current = newNode; // Move to the new node
            carry = sum / 10; // Update carry
        }
        
        // If there's any remaining carry, add it as a new node
        if (carry) {
            ListNode* lastNode = new ListNode(carry);
            current->next = lastNode;
        }
        
        return dummyHead->next; // Return the head of the resulting list
    }
};