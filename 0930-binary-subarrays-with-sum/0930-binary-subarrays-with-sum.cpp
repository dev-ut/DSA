class Solution {
public:
int numSubarraysWithSumWithAtmostgoal(vector<int>& nums, int goal)
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


        // and we will count all the no jinka sum goal se chota hi hai kyubki thy will further contribute in goal making 
        count=count+(j-i+1);
        j++;
    }
    return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
       // so diffrece btween jinka sum atmost k hai and jinka sum atmost goal-1 hai 
       // which will resultantly gives us the subarray jinka sum exactlt goal hai .

       return numSubarraysWithSumWithAtmostgoal(nums,goal)-numSubarraysWithSumWithAtmostgoal(nums,goal-1); 
    }
};