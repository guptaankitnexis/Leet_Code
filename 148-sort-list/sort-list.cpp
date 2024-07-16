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
#include <iostream> // Add necessary headers

class Solution {
public:
    ListNode* findMiddle(ListNode* head) {
        if (head == nullptr) return nullptr; // Handle empty list
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeSortedList(ListNode* leftNode, ListNode* rightNode) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while (leftNode != nullptr && rightNode != nullptr) {
            if (leftNode->val <= rightNode->val) {
                temp->next = leftNode;
                leftNode = leftNode->next;
            } else {
                temp->next = rightNode;
                rightNode = rightNode->next;
            }
            temp = temp->next;
        }
        if (leftNode != nullptr) {
            temp->next = leftNode;
        } else {
            temp->next = rightNode;
        }
        ListNode* result = dummyNode->next;
        delete dummyNode; // Free the dummy node
        return result;
    }

    ListNode* sortList(ListNode* head) {
        // base case
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* middleNode = findMiddle(head);
        ListNode* nextNode = middleNode->next;
        middleNode->next = nullptr;

        ListNode* leftNode = sortList(head);
        ListNode* rightNode = sortList(nextNode);

        return mergeSortedList(leftNode, rightNode);
    }
};