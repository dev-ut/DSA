class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int pindx=-1;
        int n=nums.size();
        // find the the no from theleft which is just smaller than the previous no '
        for(int i=n-2;i>=0;i--)
        {
           if(nums[i]<nums[i+1])
           {
            pindx=i;
            break;
           }
        }

        if(pindx==-1)  // if not found just revrse for case 2
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        // reverse the ntire partafter pindx
        reverse(nums.begin()+pindx+1,nums.end());

        // find the no just greater than the pindx to the right 

        for(int i=pindx+1;i<n;i++)
        {
            if(nums[pindx]<nums[i])
            {
                swap(nums[pindx],nums[i]);
                break;
            }
        } 

        return ;
    }
};