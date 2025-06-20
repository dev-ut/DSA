class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int n=nums.size();
        //very simple iska prefix sum mnikalo prefix array
        //aur suffix sum nikalo suffix aaray jo bhi elemt same ho whi pivot index hoga.
        //prefix
        int par[n];
        int sar[n];
        par[0]=nums[0];

        for(int i=1;i<n;i++)
        {
            par[i]=par[i-1]+nums[i];  // prefix aary taiyar hua
        }
        //suffix aary
        sar[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            sar[i]=sar[i+1]+nums[i];
        }
                  // now comapring index values
        for(int i=0;i<n;i++)
        {
            if(sar[i]==par[i]) return i;
        }
        return -1;
    }
};