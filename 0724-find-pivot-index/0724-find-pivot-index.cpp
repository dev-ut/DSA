class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
      int n=nums.size();
      // agr prefix and suffix sum nikalne ke baad jis index pr dono ki value same a rhi hogi whi hamari pivot index hogi 
      int ps[n];
      ps[0]=nums[0];
      for(int i=1;i<n;i++)
      {
        ps[i]=ps[i-1]+nums[i];
      } 
      // suffix sum
      int ss[n];
      ss[n-1]=nums[n-1];
      for(int i=n-2;i>=0;i--)
      {
        ss[i]=ss[i+1]+nums[i];
      }  
      for(int i=0;i<n;i++)
      {
        if(ss[i]==ps[i])
        {
            return i;
        }
      }
      return -1;
    }
};