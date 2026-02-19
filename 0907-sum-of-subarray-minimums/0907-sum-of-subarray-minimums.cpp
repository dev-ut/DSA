class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size();
        int mod = 1e9 + 7;

        // psi
        vector<int> psi(n, -1);
        stack<int> st;
        st.push(0);

        for(int i = 1; i < n; i++)
        {
            while(st.size() > 0 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(st.size() > 0) psi[i] = st.top();
            st.push(i);
        }

        // clear stack
        while(st.size() > 0) st.pop();

        // nsi
        vector<int> nsi(n, n);
        st.push(n - 1);

        for(int i = n - 2; i >= 0; i--)
        {
            while(st.size() > 0 && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            if(st.size() > 0) nsi[i] = st.top();
            st.push(i);
        }

        // contribution
        long long total = 0;
        for(int i = 0; i < n; i++)
        {
            long long left = i - psi[i];
            long long right = nsi[i] - i;

            total = (total + (1LL * arr[i] * left * right) % mod) % mod;
        }

        return (int)total;
    }
};
