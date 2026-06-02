class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int mxlength = 0;
        while (j < n) 
        {
            if (nums[j] == 1) 
            {
                j++; // simply agey bdhate rho
            } 
            else 
            {
                if (k > 0) 
                {
                    k--;
                    j++; // suppose we have just flipped it
                } 
                else   // window got invalid
                {
                    mxlength = max(mxlength, j - i );
                    while (nums[i] == 1)
                        i++;

                    i++; // i wil satnd at 0
                    k++; // increment the vale of k by one
                }
            }
        }
        mxlength = max(mxlength, j - i);
        return mxlength;
    }
};