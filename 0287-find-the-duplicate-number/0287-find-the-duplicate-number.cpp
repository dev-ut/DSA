class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
       // use slow and fast pointer method 
       int slow=nums[0];
        slow=nums[slow];
        int fast=nums[0];
        fast=nums[nums[fast]];

        // detect cycle
        while(slow!=fast)
        {
            slow=nums[slow];
             fast=nums[nums[fast]];
        }
        // now to find the starting pont of cycle 
        slow=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;


    }
};