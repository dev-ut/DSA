class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
     int n=nums.size();
     int lo=0;
     int hi=n-1;

     while(lo<=hi)
     {
        int mid=lo+(hi-lo)/2;
        if(nums[mid]==target) return mid;

        // checking if right part is sotred or not 
        if(nums[mid]<nums[hi])
        {
            if(target>=nums[mid] && target<=nums[hi])
            {
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        else  // if the left part is sorted 
        {
          if(target<=nums[mid] && target >=nums[lo])
          {
            hi=mid-1;
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