class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        // since we have to iterate its twice 
        int n=nums.size();
        vector<int>ans(n);

        stack<int>st;
        for(int i=2*n-1;i>=0;i--)
        {
            int actualindx=i%n;
            while(st.size()>0 && st.top()<=nums[actualindx])
            {
                st.pop();
            }
            if(st.size()==0)ans[actualindx]=-1;
            else ans[actualindx]=st.top();

            st.push(nums[actualindx]);
        }
        return ans;
    }
};