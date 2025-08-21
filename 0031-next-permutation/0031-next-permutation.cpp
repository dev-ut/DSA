class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n=nums.size();
        int pindx=-1;
        for(int i=n-2;i>=0;i--)  // sabse pehle right side m jo chota elment hai usko nikalo
        {
            if(nums[i]<nums[i+1])
            {
                pindx=i;
                break;
            }
        }

        if(pindx==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }

        reverse(nums.begin()+pindx+1,nums.end());
        int j=-1;
        for(int i=pindx+1;i<n;i++)
        {
            if(nums[pindx]<nums[i])
            {
                j=i;
                break;
            }
        }
        swap(nums[pindx],nums[j]);
        return;
    }
};