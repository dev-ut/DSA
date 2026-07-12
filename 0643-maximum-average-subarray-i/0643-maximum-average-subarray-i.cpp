class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        // kadanes algoritham 
        int n=nums.size();
       
        int prevsum=0;
        double mxavg=INT_MIN;
        for(int i=0;i<k;i++)
        {
            prevsum+=nums[i];
        }
        if(prevsum/k>mxavg) mxavg=(double)prevsum/k;
        int i=1;
        int j=k;
        
        while(j<n)
        {
           prevsum = prevsum - nums[i - 1] + nums[j];

            if ((double)prevsum / k > mxavg)
            {
                mxavg = (double)prevsum / k;
            }

            i++;
            j++;
        }

        return mxavg;
         
    }
};