class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
    //     int n=nums.size();
    //     unordered_map<int ,int> mp;
    //     for(int i=0;i<n;i++)
    //     {
    //         mp[nums[i]]++;
    //     }
    //      int missing =-1;
    //      int duplicate=-1;
       

    //    for(int i=1;i<=n;i++)
    //    {
    //       if (mp[i]==2)
    //       {
    //         duplicate=i;
    //       }
    //       else if(mp[i]==0)
    //       {
    //        missing=i;
    //       }
    //    }
    //    return{duplicate,missing};

      int i = 0;
    while (i < nums.size())
    {
        int ctindx = nums[i] - 1;

        if (nums[i] != nums[ctindx])
        {
            swap(nums[i], nums[ctindx]);
        }
        else
        {
            i++;
        }
    }

    int duplicate = -1;
    int missing = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
        {
            duplicate = nums[i]; // duplicate value present
            missing = i + 1;     // missing value
        }
    }

    return {duplicate, missing};
}

};