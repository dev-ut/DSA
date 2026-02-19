class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
      int n=nums.size();

      vector<int>pos;
      vector<int>neg;

      for(int i=0;i<n;i++)
      {
        if(nums[i]<0)
        {
            neg.push_back(nums[i]);
        }
        else
        {
            pos.push_back(nums[i]);
        }
      }
      // now make resulstntmerg evector
      vector<int>fans(n);
      int p = 0, k = 0;

    // merge alternately
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
            fans[i] = pos[p++];   // even → positive
        else
            fans[i] = neg[k++];   // odd → negative
    }

    return fans;


    }
};