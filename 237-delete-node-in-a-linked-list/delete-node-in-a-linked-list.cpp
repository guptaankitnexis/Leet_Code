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
    void deleteNode(ListNode* node) {
        // Copy the value from the next node to the current node
        node->val = node->next->val;
        
        // Link the current node to the next of next node, bypassing the next node
        node->next = node->next->next;
    }
};