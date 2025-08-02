class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int lo=0;
        int hi=height.size()-1;
        int mxcapacity=INT_MIN;
        while(lo<=hi)
        {
           mxcapacity=max(mxcapacity,(hi-lo)*min(height[lo],height[hi]));
           if(height[lo]<=height[hi]) lo++; // coz humko left side m greatest to mil hi gya now humko rihjt side m greatest chaiye
           else hi--;
        }
        return mxcapacity;

    }
};