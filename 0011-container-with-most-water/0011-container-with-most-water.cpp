class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n=height.size()-1;
        int i=0;
        int j=n;
        int marea=0;
        while(i<j)
        {
         marea=max(marea,min(height[i],height[j])*(j-i));
         if(height[i]<height[j]) i++;
         else j--;
        }
        return marea; 
    }
};