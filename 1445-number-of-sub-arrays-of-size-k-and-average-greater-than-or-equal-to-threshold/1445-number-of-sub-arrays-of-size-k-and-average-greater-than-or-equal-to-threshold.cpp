class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        // its a static sliding wndow question 
        int n=arr.size();

        int i=1;
        int j=k;
        int pws=0;
        int count=0;
         int cws=0;
        for(int i=0;i<k;i++)
        {
            pws+=arr[i];
        }
        if(pws/k >=threshold) count++;

        while(j<n)
        {
            cws=pws-arr[i-1]+arr[j];
            if(cws/k >=threshold)
            { 
                count++;
            } 
            
            pws=cws;
            i++;
            j++;
        }
        return count;
    }
};