class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
       int n=nums.size();
       if(n==0) return false;
       int lo=0;
       int hi=n-1;

       while(lo<=hi)
       {
        int mid=lo+(hi-lo)/2;
        if(nums[mid]==target) return true;
        if(nums[lo]==nums[mid]&& nums[mid]==nums[hi]) //{2,2,2,1,3,3,3,3,3}
        {
            lo++;
            hi--;
        }
        // checking for right sorted part 
        else if(nums[mid]<= nums[hi])
        {
            if(target>nums[mid] && target<=nums[hi])
            {
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        else     // checking for left sorted part 
        {
          if(target>=nums[lo] && target <nums[mid])
          {
            hi=mid-1;
          }
          else
          {
            lo=mid+1;
          }
        }
       }
       return false;  // otherwise     
    }
};