class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
      int n1=nums1.size();
      int n2=nums2.size();

      // finfing nge
      vector<int>nge(n2,-1);
      stack<int>st;
      st.push(nums2[n2-1]);
       
      for(int i=n2-2;i>=0;i--)
      {
        while(st.size()>0 && st.top()<=nums2[i])
        {
            st.pop();
        }
        if(st.size()>0) nge[i]=st.top();
    

        st.push(nums2[i]);
      }
      for(int i=0;i<nge.size();i++)
      {
        cout<<nge[i]<<",";
      }

      // now map the nums2 elemnts with nge
      unordered_map<int,int>mp;

      for(int i=0;i<nge.size();i++)
      {
        mp[nums2[i]]=nge[i];
      }
      // now match the nums1 elment in map if got mainatainsn vector push the respected value ie nge for it 
      vector<int>ans;

     for(int i=0; i<n1; i++) 
     {
        ans.push_back(mp[nums1[i]]);
     }


      return ans;

    }
};