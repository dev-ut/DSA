class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n=nums.size();
        int pindx=-1;
        //{1,3,2,4}

        for(int i=n-2;i>=0;i--)  // we are going to fnd the no whic is going to be just smaller then the no at rhe right
        {
            if(nums[i]<nums[i+1])
            { 
                pindx=i;
                break;
            }
        }
        if(pindx==-1)   // in this cause the array is [3,2,1]  this poora ulta
        {
          reverse(nums.begin(),nums.end());
          return;
        }
        // now second step is to reverse the array with pindx+1
        reverse(nums.begin()+pindx+1,nums.end());
    
        // third step is to swap the no whic is just greater then the pindx value 

        for(int i=pindx+1;i<n;i++)
        {
         if(nums[i]>nums[pindx])
         {
            swap(nums[i],nums[pindx]);
            break;
         }
        }
        return ;


    }
};