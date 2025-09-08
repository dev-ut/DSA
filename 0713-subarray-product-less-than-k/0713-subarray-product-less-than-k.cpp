class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
         int n=nums.size();
         int i=0;
         int j=0;
         int prod=1;
         int count=0;
         while(j<n)
         {
             prod = prod * nums[j];

            // shrink window agar product >= k
            while(i <= j && prod >= k)
            {
                prod = prod / nums[i];
                i++;
            }

            // yaha har bar jitne subarrays end ho rahe hain j pe
            // aur start hote hain i..j me, wo sab valid hain
            count += (j - i + 1);

            j++;
         }
         return count;    
    }
};