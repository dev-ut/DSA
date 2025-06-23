class Solution {
public:
    int search(vector<int>& ar, int target) 
    {
        int n= ar.size();
        int lo=0;
        int hi=n-1;

        while(lo<=hi)
        {
            //7 8 9 1 2 3 4 5.
            //4,5,6,7,0,1,2
            int mid= lo+(hi-lo)/2;
            if(ar[mid]==target) return mid; 
            
           if(ar[mid]<ar[hi])  // checking whether right(mid-hi) is sorted or not if sorted htao left wala part kunki check to hmrn dono m krna hai sorted or unsrted part dono m
           {
               if(target>=ar[mid] && target<=ar[hi])  //agr aisa hai to isi m hai target.  =4 man lo
               {
                  lo= mid+1;
               }   
               else
               {
                   hi=mid-1;              //1 serch krna hai to
               } 
            }

            else                 //ye tabhi hoga jb left wla soertd nhi hai ie lo-mid is sorted or not 
            {
               if(target>=ar[lo] && target<=ar[mid])  //agr lo se lekr mid tk sorted mila to// aisa hai to isi m hai target.  =8 man lo to is case m ye nhi chlega
               {
                  hi= mid-1;
               }   
               else
               {
                   lo=mid+1;              
               } 
            }
        }
        return -1;
    }
};