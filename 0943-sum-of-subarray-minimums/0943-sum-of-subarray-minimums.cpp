class Solution {
public:
   int sumSubarrayMins(vector<int>& arr) 
{
    int m = 1e9 + 7;
    //just the pure monstcak logic 
    // nselmnt from one point to left will be the smallest till that 
    int n = arr.size();
    
    vector<int> nsi(n);
    stack<int> st;

    nsi[n - 1] = n;
    st.push(n - 1);

    for (int i = n - 2; i >= 0; i--) 
    {
        while (st.size() > 0 && arr[st.top()] >= arr[i]) 
        {
            st.pop();
        }
        if (st.size() == 0) nsi[i] = n;
        else nsi[i] = st.top(); // dal do 

        st.push(i);
    }

    // previos samllest index nikal liya
    vector<int> psi(n);
    while (!st.empty()) st.pop(); // stack ko clear kr do

    psi[0] = -1;
    st.push(0);

    for (int i = 1; i < n; i++) 
    {
        while (st.size() > 0 && arr[st.top()] > arr[i]) 
        {
            st.pop();
        }
        if (st.size() == 0) psi[i] = -1;
        else psi[i] = st.top(); // dal do 

        st.push(i);
    }

    //now ab hum eak point se kitna expand kr skte hai left right on conatgoius basic ki wo us subarry ka samleeest elmnt rhe 
    long long total = 0;
    for (int i = 0; i < n; i++) 
    {
        long long left = i - psi[i];
        long long right = nsi[i] - i;
        total = (total + (arr[i] * left % m) * right % m) % m;
    }

    return total;
}

};