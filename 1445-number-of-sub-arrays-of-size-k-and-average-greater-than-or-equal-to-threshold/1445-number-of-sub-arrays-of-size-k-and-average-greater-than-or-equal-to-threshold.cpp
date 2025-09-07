class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int n=arr.size();
        int pws=0;
        int cws=0;

        int ans=0;
        for(int i=0;i<k;i++)
        {
            pws+=arr[i];
        }
        if(pws/k>=threshold) ans++;
        int j=k;
        int i=1;
        while(j<n)
        {
            cws=pws-arr[i-1]+arr[j];
            if(cws/k>=threshold)
            {
                ans++;
            }
            pws=cws;  // it will be updated upr bt iteslf
            i++;
            j++;

        }
        return ans;
    }
};