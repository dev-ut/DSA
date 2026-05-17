class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
      int n=nums.size();
      int pindx=-1;
      // find the  first no which is just smaller from the backside 
      for(int i=n-2;i>=0;i--)
      {
        if(nums[i]<nums[i+1])
        {
            pindx=i;
            break;
        }
      }
      if(pindx==-1) // sorted order
      {
        reverse(nums.begin(),nums.end());
        return;
      }
      // if we got pindx revrse the array from pindx till end
      reverse(nums.begin()+pindx+1,nums.end());

      // just find the first greatest no from the pindx
      for(int i=pindx+1;i<n;i++) 
      {
        if(nums[pindx]<nums[i])
        {
            swap(nums[i],nums[pindx]);
            break;
        }
      }    
    }
};