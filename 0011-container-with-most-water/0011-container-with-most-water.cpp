class Solution {
public:
    int maxArea(vector<int>& height) 
    {
       int i=0;
       int j=height.size()-1;
       int mxcap=INT_MIN;
       while(i<=j)
       {
         mxcap=max(mxcap,min(height[i],height[j])*(j-i));
         if(height[i]<=height[j]) i++;
         else j--;
       }
     return mxcap;
    }
};