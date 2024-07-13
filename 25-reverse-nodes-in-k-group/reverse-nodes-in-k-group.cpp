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
ListNode* reverseNode(ListNode* head) {
    // Base case: if head is null or it's the last node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* newHead =
        reverseNode(head->next);     // Recur for the rest of the list
    ListNode* nextNode = head->next; // Store the next node
    nextNode->next = head;           // Reverse the link
    head->next = nullptr;            // Set the next of the current node to null
    return newHead;                  // Return the new head of the reversed list
}

ListNode* findKnode(ListNode* temp, int k) {
    k--;
    while (temp != NULL && k > 0) {
        temp = temp->next;
        k--;
    }
    return temp;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp != NULL) {
            ListNode* kThnode = findKnode(temp, k);
            if (kThnode == NULL) {
                if (prev != NULL) {
                    prev->next = temp;
                }
                break;
            }
            ListNode* nextNode = kThnode->next;
            kThnode->next = NULL;
            ListNode* newHead = reverseNode(temp); // Reverse the sublist

            if (prev != NULL) {
                prev->next = newHead;
            } else {
                head = newHead;
            }

            prev = temp;
            temp = nextNode;
        }
        return head;
    }
};