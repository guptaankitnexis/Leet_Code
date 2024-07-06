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
    // Main function to reverse the list
    ListNode* reverseList(ListNode* head) {
        return reverseLL(head, nullptr); // Call helper function with head and initial previous as nullptr
        // return reverseLLRR(head); // Uncomment to use the other reversal method
    }
    
    // Recursive helper function to reverse the list
    ListNode* reverseLL(ListNode* current, ListNode* previous) {
        // Base case: if current is null, return previous (new head)
        if (current == nullptr) {
            return previous;
        }
        ListNode* nextNode = current->next; // Store the next node
        current->next = previous; // Reverse the link
        previous = current; // Move previous to current
        return reverseLL(nextNode, previous); // Recur for the next node
    }
     
    // Alternative recursive method to reverse the list
    ListNode* reverseLLRR(ListNode* head) {
        // Base case: if head is null or it's the last node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = reverseLLRR(head->next); // Recur for the rest of the list
        ListNode* nextNode = head->next; // Store the next node
        nextNode->next = head; // Reverse the link
        head->next = nullptr; // Set the next of the current node to null
        return newHead; // Return the new head of the reversed list
    }
};
