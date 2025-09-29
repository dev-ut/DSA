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
       // dekho approch yrhi rhegi iski ki jiski length bdi hogi usko utna aagey move krnge aur jahn a nd b barabr ho jyenge return kr denge wo position 
       ListNode *tempa=headA;
       ListNode *tempb=headB;

       // dono ki length nikl lo
       int lenA=0,lenB=0;
       while(tempa!=NULL)
       {
        tempa=tempa->next;
        lenA++;
        }
        while(tempb!=NULL)
       {
        tempb=tempb->next;
        lenB++;
        }
        // now dekhnge kiski length bdi hai
        tempa=headA;
        tempb=headB;

        if(lenA>lenB)
        {
            int diff=lenA-lenB;
            // jitna diffrence aya hai utna gey pointer kr do of greater list 
            while(diff!=0)
            {
                tempa=tempa->next;
                diff--;
            }
            while(tempa!=tempb)
            {
                tempa=tempa->next;
                tempb=tempb->next;
            }
        }
        else
        {
           int diff=lenB-lenA;
            // jitna diffrence aya hai utna gey pointer kr do of greater list 
            while(diff!=0)
            {
                tempb=tempb->next;
                diff--;
            }
            while(tempa!=tempb)
            {
                tempa=tempa->next;
                tempb=tempb->next;
            }  
        }

        // at last they will meet and come out of loop at somepoint 
        return tempa ;   // the exact point where thery are meeting

    }
};