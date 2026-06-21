class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n=nums.size();
       vector<vector<int>>fans;
       sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int sum=0;
            int j=i+1;
            int k=n-1;
            if(i==0 || nums[i]!=nums[i-1])
            {
                while(j<k)
                {
                    sum=nums[i]+nums[j]+nums[k];
                    if(sum==0)
                    {
                      fans.push_back({nums[i],nums[j],nums[k]});
                      j++;
                      k--;

                      //supoose beech m there exists multiple duplicate elment then 
                      while(j<k && nums[j]==nums[j-1]) j++;
                      while(k>j && nums[k]==nums[k+1])k--;
                    }
                    else if(sum<0)
                    {
                        j++;
                    }
                    else
                    {
                        k--;
                    }

                }
            }
        }
        return fans;
    }
};