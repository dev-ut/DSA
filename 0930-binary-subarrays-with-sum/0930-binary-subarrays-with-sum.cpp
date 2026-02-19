class Solution {
public:
int numSubarraysWithSumAtmostK(vector<int>& nums, int goal)
{
    int n=nums.size();
    int i=0;
    int j=0;
    int sum=0;
    int count=0;
    while(j<n)
    {
      sum=sum+nums[j];
      while(sum>goal && i<=j)
      {
        sum=sum-nums[i];
        i++;
      }
      count=count+(j-i+1);  // it will give no of the the subarry at most k from every indx 
      j++;
    }
    return count;
}
int numSubarraysWithSum(vector<int>& nums, int goal) 
{
    return numSubarraysWithSumAtmostK(nums,goal)-numSubarraysWithSumAtmostK(nums,goal-1);
}

};