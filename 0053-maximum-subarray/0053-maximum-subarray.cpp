class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int msum=nums[0];
        int csum=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            if(csum+nums[i]>nums[i])
            {
                csum=csum+nums[i];
            }
            else
            {
                csum=nums[i];
            }

            if(csum>msum)
            {
                msum=csum;
            }
        }
        return msum;

        
    }
};