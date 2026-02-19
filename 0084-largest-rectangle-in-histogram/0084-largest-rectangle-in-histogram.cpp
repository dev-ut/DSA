class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        vector<int>psi(n,-1);
        vector<int>nsi(n,n);
        stack<int>st;
        st.push(0);
        // now finding psi
        for(int i=1;i<n;i++)
        {
           while(st.size()>0 && heights[st.top()]>= heights[i])
           {
            st.pop();
           }
           if(st.size()>0)psi[i]=st.top();

           st.push(i);
        }

        // now finding nsi
        stack<int>gt;
        gt.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
           while(gt.size()>0 && heights[gt.top()]>= heights[i])
           {
            gt.pop();
           }
           if(gt.size()>0)nsi[i]=gt.top();

           gt.push(i);
        }

        int mxarea=0;

        for(int i=0;i<n;i++)
        {
            int area=heights[i] *(nsi[i]-psi[i]-1);
            mxarea=max(mxarea,area);
        }
        return mxarea;

    }
};