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
    ListNode* merge(ListNode* a, ListNode* b)
    {
        // dummy node banaya easy attach ke liye
        ListNode* c = new ListNode(-1);
        ListNode* tempc = c;

        while (a != NULL && b != NULL)
        {
            if (a->val <= b->val)
            {
                tempc->next = a;
                a = a->next;
            }
            else
            {
                tempc->next = b;
                b = b->next;
            }
            tempc = tempc->next;
        }

        // bachi hui list attach kar do
        if (a != NULL) tempc->next = a;
        if (b != NULL) tempc->next = b;

        return c->next;
    }

    ListNode* sortList(ListNode* head) 
    {
        // base case
        if (head == NULL || head->next == NULL) return head;

        // middle nikalne ke liye slow-fast
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // ab do parts me tod do
        ListNode* a = head;
        ListNode* b = slow->next;
        slow->next = NULL;

        // recursion se sort karo
        a = sortList(a);
        b = sortList(b);

        // dono ko merge karo
        return merge(a, b);
    }
};
