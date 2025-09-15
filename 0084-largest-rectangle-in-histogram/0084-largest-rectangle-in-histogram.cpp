class Solution {
public:
    int largestRectangleArea(vector<int>& arr) 
    {
     
    int n=arr.size();

    // Previous Smaller Index (PSI)
    vector<int>psi(n,-1);
    stack<int>st;
    st.push(0);
    for(int i=1;i<n;i++)
    {
        while(st.size()>0 && arr[st.top()]>=arr[i])
        {
            st.pop(); // yaha pe pop karna tha
        }

        if(st.size()>0) psi[i]=st.top(); // push_back nahi karna
        st.push(i);
    }

    // Next Smaller Index (NSI)
    vector<int>nsi(n,n);
    stack<int>gt;
    gt.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        while(gt.size()>0 && arr[gt.top()]>=arr[i])
        {
            gt.pop(); // yaha bhi pop karna tha
        }

        if(gt.size()>0) nsi[i]=gt.top(); // push_back ke jagah assignment
        gt.push(i);
    }

    int maxarea=0;
    for(int i=0;i<n;i++)
    {
        int area=arr[i]*(nsi[i]-psi[i]-1);
        maxarea=max(maxarea,area);
    }
    return maxarea;
}
};