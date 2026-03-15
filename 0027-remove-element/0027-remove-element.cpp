class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
      int i=0;
      for(int j=0;j<nums.size();j++)
      {
        if(nums[j]!=val)
        {
            nums[i]=nums[j];   // ye tab hi smjh ayega whne youu will reach the condition where u have to alter the two pointer sin pace 
            i++;
        }
      } 
      return i;
    }
};
// Note : always rember one static other dynaimc 
//2nd  both dynaic one after the another 
// in place revral place the i at front and j at last for in place reversla of anyarray or string .