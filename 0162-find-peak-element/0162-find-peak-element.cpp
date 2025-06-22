class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int n=nums.size();

        int lo=0;
        int hi=n-1;
        int peak=-1;
        if(n==1) return 0;
      while(lo<=hi)
      {
       int mid=lo+(hi-lo)/2;
       if(mid==0)  // when arry is 4321  // step 2
       {
            if(nums[mid]>nums[mid+1])
            {
                return mid;
            }
            else lo=mid+1;
       }

     if(mid==n-1)  // when arry is 1234  // step 3
       {
            if(nums[mid]>nums[mid-1])
            {
                return mid;
            }
            else hi=mid-1;
       }

     else if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])  // step 1 basic approch yhn se
      {
       return mid;
      }
      else if(nums[mid]<nums[mid+1])
      {
        lo=mid+1;
      }
      else hi=mid-1;
    
     }
     // if no peak is found
     return -1;

    }
};