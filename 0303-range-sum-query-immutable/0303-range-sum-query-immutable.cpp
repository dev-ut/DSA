class NumArray {
public:
 vector<int>pref;  // ye for prefix sum 
NumArray(vector<int>& nums) 
    {
        pref=vector<int>(nums.size()); // this is the way of writing when pre pehle se hi eclared hai and e want to create and reinitize value of same size
        int n=nums.size();
       
       
        // now we will make prefix array 
        pref[0]=nums[0];
        
        for(int i=1;i<n;i++)
        {
             pref[i]=pref[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) 
    {
         if(left==0) return pref[right];
         return pref[right]-pref[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */