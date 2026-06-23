class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
      int n1=nums1.size();
      int n2=nums2.size();
      stack<int>st;
      vector<int>pge(n2);
      for(int i=n2-1;i>=0;i--)
      {
        while(st.size()>0 && st.top()<nums2[i])
        {
            st.pop();
        }
        if(st.size()==0) pge[i]=-1;
        else pge[i]=st.top();

        st.push(nums2[i]);
      }  
      unordered_map<int,int>mp;
      for(int i=0;i<n2;i++)
      {
        mp[nums2[i]]=pge[i];
      }  
      vector<int>fans;
      for(int i=0;i<n1;i++)
      {
         fans.push_back(mp[nums1[i]]);
      }

      return fans;
    }
};