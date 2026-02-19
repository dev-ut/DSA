class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==1) return nums[0];
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            // mid = 0 case
            if (mid == 0)
            {
                if (nums[mid] != nums[mid + 1]) 
                {
                    return nums[mid];
                }
                else lo = mid + 1;
            }
            // mid = n-1 case
            else if (mid == n - 1)
            {
                if (nums[mid] != nums[mid - 1]) return nums[mid];
                else hi = mid - 1;
            }
            else
            {
                // unique element check
                if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                {
                    return nums[mid];
                }

                // deciding direction
                // if mid even hai and pair up ho jata hai apne next elmnt ke sath and 
                // if nid is odd nad pair with prev elmnt means unique elmnt is at right
                if ( (mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                     (mid % 2 == 1 && nums[mid] == nums[mid - 1]) )
                {
                    lo = mid + 1;   // right side
                }
                else
                {
                    hi = mid - 1;   // left side
                }
            }
        }
        return -1;
    }

};