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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
     //  Code Here
        int sizea=0;
        int sizeb=0;
        ListNode* t1=headA;
        ListNode* t2=headB;
        while(t1!=NULL)
        {
            sizea++;
            t1=t1->next;
        }
         while(t2!=NULL)
        {
            sizeb++;
            t2=t2->next;
        }
        int diff=0;
         t1=headA;
         t2=headB;
        if(sizea>sizeb) 
        {
            diff=sizea-sizeb;
           for(int i=0;i<diff;i++)
            {
               t1=t1->next; 
            }
            
        }
        else
        {
            diff=sizeb-sizea;
            for(int i=0;i<diff;i++)
            {
                t2=t2->next;
            }
        }
        while(t1!=t2)
        {
            t1=t1->next;
            t2=t2->next;
        }
        return t1;
    }
};