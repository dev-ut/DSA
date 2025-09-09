class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size();
        int mod = 1e9 + 7;

        // Next smaller index
        vector<int> nsi(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) 
        {
            while (!st.empty() && arr[st.top()] > arr[i]) 
            {
                st.pop();
            }
            if (!st.empty()) nsi[i] = st.top();
            st.push(i);
        }

        // Previous smaller index
        vector<int> psi(n, -1);
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) 
        {
            while (!st.empty() && arr[st.top()] >= arr[i]) 
            { // >= is important
                st.pop();
            }
            if (!st.empty()) psi[i] = st.top();
            st.push(i);
        }

        // Contribution calculation
        long long total = 0;
        for (int i = 0; i < n; i++) 
        {
            long long left = i - psi[i];
            long long right = nsi[i] - i;
            total = (total + (1LL * arr[i] * left * right) % mod) % mod;
        }

        return (int)total;
    }
};
