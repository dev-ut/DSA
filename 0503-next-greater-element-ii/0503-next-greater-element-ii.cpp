class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n=nums.size();
        // we have to make this array loop two times completely so can we acess the 
        //next greatest elment in loop 
        vector<int>ans(n);
        stack<int>st;

        for(int i=2*n-1;i>=0;i--)
        {
            int actualindex=i%n;

            while(st.size()>0 && st.top()<=nums[actualindex])
            {
                st.pop();
            }
            if(st.size()==0)ans[actualindex]=-1;
            else ans[actualindex]=st.top();

            st.push(nums[actualindex]);

        }
        return ans;
    }
};