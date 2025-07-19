class Solution {
public:
    void nextPermutation(vector<int>& nums){   // take example 3 4 2
        int n=nums.size();
        int pind = -1;
        //1 finding pivot
        for(int i=n-2;i>=0;i--)
        {
          if( nums[i]<nums[i+1])
          {
            pind=i;
            break;
          }
        }
    // ex-2 dekho have to return if araay is already sorted 4 321
    if (pind == -1) //mmlb ki apke paas jo vector tha wo alreay  sabse bda tha so reverse 
    {
      reverse(nums.begin(),nums.end());
      return;
    }
   //2 to sort / reverse after pivot
    reverse(nums.begin()+(pind+1),nums.end());
    //3 step hai ki find just greatest elemt after pivot
    int j=-1;
    for(int i=pind+1;i<n;i++)
    {
        if(nums[i]>nums[pind])
        {
            j=i;
            break;
        }
    }
//4 swap kr do pivot or uske agle elmet se
    swap(nums[pind],nums[j]);
return;
}


};