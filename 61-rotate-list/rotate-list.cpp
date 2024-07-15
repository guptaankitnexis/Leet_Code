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
    ListNode* rotateRight(ListNode* head, int k) {
        // Return early if list is empty or k is 0 (no rotation needed)
        if(head == NULL || k == 0){
            return head;
        }

        ListNode* tail = head;
        ListNode* temp = head;
        int length = 1;

        // Calculate the length of the list
        while(tail->next != NULL){
            tail = tail->next;
            length++;
        }

        // If k is a multiple of length, list remains unchanged
        if(k % length == 0){
            return head;
        }

        // Adjust k to be within the range of the list length
        k = k % length;

        // Connect the last node to the head to make it circular
        tail->next = head;

        // Find the new tail, which is (length - k) steps from the start
        int leftLength = length - k;
        for(int i = 1; i < leftLength; i++){
            temp = temp->next;
        }

        // Set the new head to be the node after the new tail
        head = temp->next;

        // Break the circle
        temp->next = NULL;

        return head;
    }
};
