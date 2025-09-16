class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        // ok so the length of m is exactlt m+n 
        // so we will actlayy start the merging from the first 0th elment in nums1
        int i=0;
        int j=0;
       vector<int> temp; // temporary array for sorted result

        while(i < m && j < n) 
        {
            if(nums1[i] <= nums2[j]) 
            {
                temp.push_back(nums1[i++]);
            } 
            else 
            {
                temp.push_back(nums2[j++]);
            }
        }
        // nums1 ke remaining elements
        while(i < m) 
        {
            temp.push_back(nums1[i++]);
        }
          // nums2 ke remaining elements
        while(j < n) 
        {
            temp.push_back(nums2[j++]);
        }

        // ab temp ka data nums1 me overwrite karna
        for(int k = 0; k < m + n; k++) 
        {
            nums1[k] = temp[k];
        }
       
    }
};