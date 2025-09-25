class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
       int n=nums.size();
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++)
       {
        mp[nums[i]]++;
       }
       vector<int>ans;
       for(auto it :mp)
       {
        int key=it.first;

        if(mp[key]>1)
        {
          ans.push_back(key);
        }
       }
       return ans;
        
    }
};