class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int n=nums.size();

    // take 2 arrays whensover u have to find minimum in  roated bs 
    //1,2,3,4,,5,6,7,8,9 
    //9,8,7,6,5,4,3,2,1     .. one sorted in ascending order ... sorted in descending order 
    

        int lo=0;
        int hi=n-1;
        int ans=INT_MAX;
        while(lo<=hi)
        {
            int mid= lo+(hi-lo)/2;
            if(nums[mid]<=nums[hi])   // it mans it is right ssorted
            {
                ans=min(ans,nums[lo]);
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
                ans=min(ans,nums[mid]);
            }
        }
        return ans;

    }
};