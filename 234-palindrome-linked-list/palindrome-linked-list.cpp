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
    // Function to check if a linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Use two pointers to find the middle of the list
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of the list
        ListNode* newNode = reverseLL(slow->next);
        ListNode* first = head;
        ListNode* second = newNode;
        
        // Compare the first and second halves
        while (second != NULL) {
            if (first->val != second->val) {
                return false; // Not a palindrome
            }
            first = first->next;
            second = second->next;
        }
        
        // Restore the original order of the list
        reverseLL(newNode);
        return true; // Is a palindrome
    }

    // Function to reverse a linked list
    ListNode* reverseLL(ListNode* head) {
        // Base case: if the list is empty or has only one node
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        // Recursively reverse the rest of the list
        ListNode* newHead = reverseLL(head->next);
        ListNode* front = head->next;
        
        // Adjust the pointers to reverse the current nodes
        front->next = head;
        head->next = nullptr;
        
        return newHead; // Return the new head of the reversed list
    }
};