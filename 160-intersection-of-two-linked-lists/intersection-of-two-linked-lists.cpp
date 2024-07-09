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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA; // Pointer for list A
        ListNode* temp2 = headB; // Pointer for list B
        
        while (temp1 != temp2) { // Traverse until pointers meet
            temp1 = temp1->next; // Move to next node in list A
            temp2 = temp2->next; // Move to next node in list B
            
            if (temp1 == temp2) // If intersection found
                return temp1;
            else if (temp1 == nullptr) // If temp1 reaches end of list A, start from headB
                temp1 = headB;
            else if (temp2 == nullptr) // If temp2 reaches end of list B, start from headA
                temp2 = headA;
        }
        
        return temp1; // Return the intersection node or nullptr if no intersection
    }
};
