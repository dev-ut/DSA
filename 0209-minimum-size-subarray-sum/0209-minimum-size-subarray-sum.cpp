class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
      int n=nums.size();
      int i=0 ,j=0,sum=0,minlength=INT_MAX;

      while(j<n)
      {
        sum=sum+nums[j];
        while(sum>=target && i<=j)
        {
            minlength=min(minlength,j-i+1);
            sum=sum-nums[i];
            i++;
        }
        j++;
      }
      return (minlength!=INT_MAX)? minlength:0;

    }
};