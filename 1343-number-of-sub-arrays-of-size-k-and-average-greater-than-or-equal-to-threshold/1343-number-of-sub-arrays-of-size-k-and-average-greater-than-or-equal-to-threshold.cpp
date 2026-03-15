class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) 
    {
       int n=nums.size();
       int pwsum=0;
       int count=0;
       for(int i=0;i<k;i++)
       {
        pwsum=pwsum+nums[i];
       }
       if(pwsum/k >= threshold) count++;

       int i=1;
       int j=k;
       int cwsum=0;
       while(j<n)
       {
         cwsum=pwsum-nums[i-1]+nums[j];
         if(cwsum/k>=threshold) count++;

         pwsum=cwsum;
         i++;
         j++;
       }
       return count;   
    }
};