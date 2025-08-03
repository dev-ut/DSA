class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n=nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int length;
        int minlength=INT_MAX;

        while(j<n)
        {
            sum=sum+nums[j];
            while(sum>=target && i<=j)
            {
                minlength=min(minlength,j-i+1);
                sum=sum-nums[i];   // window mai se peehla i ka sum subtract kiya 
                i++;  // i shribnk kiya 
            }

            j++;
            
        }
        if(minlength==INT_MAX) return 0;  // cae 3 ke liye h hta kr dekh lo
        return minlength;
        
        
    }
};