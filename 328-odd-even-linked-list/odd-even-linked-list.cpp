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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {  // If the list is empty, return NULL
            return NULL;
        }
        
        ListNode* oddNode = head;  // Initialize oddNode to the head of the list
        ListNode* evenNode = head->next;  // Initialize evenNode to the second node
        ListNode* evenFirstNode = head->next;  // Keep the first even node to connect later
        
        // Traverse the list, rearranging nodes
        while (evenNode != NULL && evenNode->next != NULL) {
            oddNode->next = oddNode->next->next;  // Link the next odd node
            evenNode->next = evenNode->next->next;  // Link the next even node

            oddNode = oddNode->next;  // Move to the next odd node
            evenNode = evenNode->next;  // Move to the next even node
        }
        
        oddNode->next = evenFirstNode;  // Connect the end of odd nodes to the first even node
        return head;  // Return the modified list
    }
};
