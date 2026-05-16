class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int indx=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
          if(nums[i]!=0)
          {
            nums[indx++]=nums[i];
          }
        }

        for(int i=indx;i<n;i++)
        {
            nums[i]=0;
        }
        return ;
    }
};