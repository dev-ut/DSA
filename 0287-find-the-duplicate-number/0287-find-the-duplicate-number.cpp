class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
          mp[nums[i]]++;
        }

        for(auto it :mp)
        {
            int key=it.first;
            if(mp[key]>=2)
            {
                return key;
            }
        }
        return 0;
    }
};