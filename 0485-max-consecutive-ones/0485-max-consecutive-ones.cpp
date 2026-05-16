class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
{
    int i = 0;
    int j = 0;
    int mxc = 0;
    int n = nums.size();

    while(j < n)
    {
        if(nums[j] != 1)
        {
            if(i<n)i = j + 1;
        }
        else
        {
            mxc = max(mxc, j - i + 1);
        }
        j++;
    }
    return mxc;
}

};