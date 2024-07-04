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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* current = head->next; // Skip the initial zero node
        ListNode* mergedNode = new ListNode(); // Dummy node to start the merged list
        ListNode* mergedHead = mergedNode; // Head of the merged list

        while (current->next != nullptr) {
            if (current->val != 0) {
                // Accumulate values until a zero node is encountered
                mergedNode->val += current->val;
            } else {
                // Create a new node to continue the merged list
                ListNode* newNode = new ListNode();
                mergedNode->next = newNode;
                mergedNode = newNode;
            }
            current = current->next; // Move to the next node
        }
        return mergedHead; // Return the head of the merged list
    }
};