/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {} // Constructor to initialize the node with a value and set next to NULL
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return head; // If the list is empty, return NULL
        ListNode* temp = head; // Temporary pointer to traverse the list
        map<ListNode*, int> mpp; // Map to store visited nodes
        while(temp != NULL) {
            if(mpp.find(temp) != mpp.end()) {
                return temp; // Cycle detected, return the starting node of the cycle
            }
            mpp[temp] = 1; // Mark the node as visited
            temp = temp->next; // Move to the next node
        }
        return NULL; // No cycle found, return NULL
    }
};