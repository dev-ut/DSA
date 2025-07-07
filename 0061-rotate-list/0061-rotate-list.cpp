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
    
 ListNode* rotateRight(ListNode* head, int k) 
 {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find size
        ListNode* temp = head;
        int size = 1;
        while (temp->next) {
            temp = temp->next;
            size++;
        }

        // Step 2: Update k
        k = k % size;
        if (k == 0) return head;

        // Step 3: Make it circular
        temp->next = head; // last node connects to head

        // Step 4: Move to new tail (size - k - 1)th node
        int stepsToNewTail = size - k;
        temp = head;
        for (int i = 0; i < stepsToNewTail - 1; i++) 
        {
            temp = temp->next;
        }

        // Step 5: Set new head and break the loop
        ListNode* newHead = temp->next;
        temp->next = nullptr;

        return newHead;
    }
};
