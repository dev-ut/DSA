class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
      int n=nums.size();
      int lo=0;
      int hi=nums.size()-1;
      while(lo<=hi)
      {
       int mid=lo+(hi-lo)/2;
       if(mid==0)   // if the array is sorted 4,3,2,1
       {
        if(nums[mid]>nums[mid+1])
        {
            return mid;
        }
        else
        {
          lo=mid+1;
        }
       }
       if(mid==n-1)  // if the array is sorted 1,2,3,4
       {
        if(nums[mid]>nums[mid-1])
        {
            return mid;
        }
        else
        {
          lo=mid+1;
        }
       }
        else if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])  // start from here basic approch
        {
            return mid;
        }
        else if(nums[mid]<nums[mid+1])
        {
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }

      }
      return -1;    
    }
};