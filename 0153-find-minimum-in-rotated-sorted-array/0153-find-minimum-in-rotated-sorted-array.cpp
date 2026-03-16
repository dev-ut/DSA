class Solution {
public:
    int findMin(vector<int>& nums) 
    {
      int n=nums.size();
      int lo=0;
      int hi=n-1;
      int ans=INT_MAX;
      while(lo<=hi)
      {
        int mid=lo+(hi-lo)/2;
        //left sorted part check for min 
        if(nums[lo]<=nums[mid])
        {
            ans=min(ans,nums[lo]);
            lo=mid+1;               // isse na hmara rigt part acess ho ja rha hai asani se 
        }
        else
        {
            hi=mid-1;
           ans=min(ans,nums[mid]);
           
        }

      }
      return ans;    
    }
};
//Note : expmaple first wala hi rkho {3,4,5,1,2};