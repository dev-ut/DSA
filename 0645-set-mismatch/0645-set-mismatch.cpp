class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_map<int ,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
         int missing =-1;
         int duplicate=-1;
       

       for(int i=1;i<=n;i++)
       {
          if (mp[i]==2)
          {
            duplicate=i;
          }
          else if(mp[i]==0)
          {
           missing=i;
          }
       }
       return{duplicate,missing};
       
    }
};