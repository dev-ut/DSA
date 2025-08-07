class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
       int slow=nums[0];
        int fast=nums[0];
        slow=nums[slow];
        fast=nums[nums[fast]];
        // detect cycle

        while(slow!=fast)
        {
            // slow ko ek se bdhao fast ko 2 se
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
       
        // now ab dekho cycle start khan se ho rhi very imp

        slow=nums[0];
        while(slow!=fast)
        {
            //ek ek se bdhao
            slow=nums[slow];
            fast=nums[fast];

        }
         return slow;
    }
};