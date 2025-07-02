class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i=0;   // i ko yhn pr stop kr diya at index 0
        int n=nums.size();
        for(int j=i+1;j<n;j++)
        {
            if(nums[i]!=nums[j])
            {
                i++;  //i =1 ho hya whn pr index 2nd ki value daal do 
                nums[i]=nums[j];
            }
        }
        return {i+1} ;//kunki yhi wo position hogi jahn elments are distinct 
    }
};