class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
      int n=nums.size();
      int fi=-1;
      int li=-1;
      int lo=0;
      int hi=n-1;
      while(lo<=hi)
      {
        int mid= lo+(hi-lo)/2;
        if(nums[mid]==target)
        {
          fi=mid;
          hi=mid-1;
        }
        else if(nums[mid]<target)
        {
         lo=mid+1;
        }
        else
        {
          hi=mid-1;
        }

      }
      lo=0;
      hi=n-1;
      while(lo<=hi)
      {
         int mid= lo+(hi-lo)/2;
        if(nums[mid]==target)
        {
          li=mid;
          lo=mid+1;
        }
        else if(nums[mid]<target)
        {
         lo=mid+1;
        }
        else
        {
          hi=mid-1;
        }
      }
      if(li==-1 && fi==-1) return{fi,li};
      else return {fi,li};
    }
};