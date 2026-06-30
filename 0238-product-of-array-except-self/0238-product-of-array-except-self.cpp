class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
      // without devision method 
      // rembeber whensoever we want the values from index i could be precomputed we use 
      // preix and suffix prdouct from that index i;
      int n=nums.size();
      vector<int>ans(n);
      ans[0]=1;  // as product of no before index 0 will be 1
      for(int i=1;i<n;i++)
      {
        ans[i]=ans[i-1]*nums[i-1];
      }
      int suffix=1;
      for(int i=n-1;i>=0;i--)
      {
        ans[i]=ans[i]*suffix;
        suffix=suffix*nums[i];
      } 

      return ans;   
    }
};