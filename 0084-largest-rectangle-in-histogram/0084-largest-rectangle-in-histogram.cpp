class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
         int n=arr.size();
        int nsi[n];
        nsi[n-1]=n;
        stack<int> st;
        st.push(n-1);

        for(int i=n-2;i>=0;i--)
        {
            while(st.size()>0 && arr[st.top()]>=arr[i])     // greater men hota hai st.top()<=arr[i];**
            {
               st.pop();
            }
            if(st.size()==0) nsi[i]=n;
            else nsi[i]=st.top();

            st.push(i);
        }
        // to get prev smallest element index; same logic
        int psi[n];
        stack<int> gt;
        psi[0]=-1;
        gt.push(0);

        for(int i=1;i<n;i++)
        {
            while(gt.size()>0 && arr[gt.top()]>=arr[i])
            {
               gt.pop();
            }
            if(gt.size()==0) psi[i]=-1;
            else psi[i]=gt.top();

            gt.push(i);
        }
        // now area
        int maxarea=0;
        for(int i=0;i<n;i++)
        {
            int area=arr[i]*(nsi[i]-psi[i]-1);  // hr eak point ke liye left or right exapnd krenge
            maxarea= max(area,maxarea);
        }
        return maxarea;
    }
};