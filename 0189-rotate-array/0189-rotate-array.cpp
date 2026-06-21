class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        k=k%n;  // effective rotations

        if(k==0 || n==0 || k==n) return;

        vector<int> temp(k);
        // now copy h elments to the new vector 
        for(int i=0;i<k;i++)
        {
           temp[i]=nums[n-k +i];
        }
        // now shift the elments to the right by k positions
        /// it cant be made possible by forward as it chnges the emnt so go backwards

        for(int i=n-1;i>=k;i--)
        {
            nums[i]=nums[i-k];  // just shift k elments only 
        }
        // copy the reamaing elments
        for(int i=0;i<k;i++)
        {
            nums[i]=temp[i];
        }
        return;

    }
};