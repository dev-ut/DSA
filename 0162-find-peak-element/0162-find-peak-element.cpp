class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        // take i2,3,4,5 
        // 5,4,3,2,1
        int n= nums.size();
        int lo=0;
        int hi=n-1;
        if(n==1)return 0;

        while(lo<=hi)
        {
          int mid=lo+(hi-lo)/2;
          if(mid==0)
          {
            if(nums[mid+1]<nums[mid]) return mid;
            else lo=mid+1;
          }
          else if(mid==n-1)
          {
            if(nums[mid]>nums[mid-1]) return mid;
            else hi=mid-1;
           
          }
          else if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
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