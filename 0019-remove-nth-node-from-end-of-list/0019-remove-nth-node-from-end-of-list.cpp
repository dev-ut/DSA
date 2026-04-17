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
ListNode* removeNthFromEnd(ListNode* head, int n) 
{
        int size = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        // agar first node delete karni ho
        if (size == n) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int it = size - n;
        temp = head;

        while (it > 1) {
            temp = temp->next;
            it--;
        }

        ListNode* actualnode = temp->next;
        temp->next = actualnode->next;
        delete actualnode;

        return head;
    }
};