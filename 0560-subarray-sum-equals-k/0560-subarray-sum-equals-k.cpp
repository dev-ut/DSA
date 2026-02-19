class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
           int n= nums.size();
        // create prefix array in palce
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        // create and loop up and aad the frequency if found
         for(int i=0;i<n;i++)
        {
            cout<<nums[i]<<",";
        }
        unordered_map<int,int> map;

        int count=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==k)count++;   // if dierct k== index value 
            int rem=nums[i]-k;    
            if(map.find(rem)!=map.end()) count=count+map[rem];
            
            map[nums[i]]++;
        }
        return count;
    }
};