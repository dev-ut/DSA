class Solution {
public:
    // Monotonic stack to find Next Smaller Element (NSE) and Previous Smaller Element (PSE)
vector<int> nse1(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);  // Initialize with size n
    stack<int> st;

    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        result[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return result;
}

vector<int> pse1(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);  // Initialize with size n
    stack<int> st;

    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        result[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return result;
}

// Monotonic stack to find Next Larger Element (NLE) and Previous Larger Element (PLE)
vector<int> nse2(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);  // Initialize with size n
    stack<int> st;

    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }
        result[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return result;
}

vector<int> pse2(vector<int>& arr) 
{
    int n = arr.size();
    vector<int> result(n);  // Initialize with size n
    stack<int> st;

    for(int i = 0; i < n; i++) 
    {
        while(st.size()>0 && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        result[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return result;
}

long long subArrayRanges(vector<int>& nums) 
{
    int n = nums.size();

    // Chhote aur bade elements ke liye PSE aur NSE calculate kar rahe hain
    vector<int> small_pse = pse1(nums);
    vector<int> small_nse = nse1(nums);

    vector<int> large_pse = pse2(nums);
    vector<int> large_nse = nse2(nums);

    long long largesttotal = 0;
    long long smallesttotal = 0;

    for (int i = 0; i < n; i++) 
    {
        // Smallest value ka contribution calculate kar rahe hain
        int leftSmall = i - small_pse[i];
        int rightSmall = small_nse[i] - i;
        smallesttotal += (long long)leftSmall * rightSmall * nums[i];

        // Largest value ka contribution calculate kar rahe hain
        int leftLarge = i - large_pse[i];
        int rightLarge = large_nse[i] - i;
        largesttotal += (long long)leftLarge * rightLarge * nums[i];
    }

    // Final answer is largesttotal - smallesttotal
    return largesttotal - smallesttotal;
}

};