class Solution {
public:
    int findPeakElement(vector<int>& nums) 
{
    int n = nums.size();
    int lo = 0;
    int hi = nums.size() - 1;

    if(n == 1) return 0; // ek element hai toh wahi peak hai

    while(lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if(mid == 0)   // agar first element par ho
        {
            if(nums[mid] > nums[mid+1])
            {
                return mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        else if(mid == n-1)  // agar last element par ho
        {
            if(nums[mid] > nums[mid-1])
            {
                return mid;
            }
            else
            {
                hi = mid - 1;
            }
        }
        else if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1])  // basic approach
        {
            return mid;
        }
        else if(nums[mid] < nums[mid+1])
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return -1;    
}
};
