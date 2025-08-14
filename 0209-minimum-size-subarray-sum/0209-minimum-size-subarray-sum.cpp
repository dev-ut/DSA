class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) 
    {
       // is a varibale slinding window techique 

       int n=arr.size();
       int i=0;
       int j=0;
       int sum=0;
       int mnlgth=INT_MAX;
       while(j<n)
       {
         sum+=arr[j];

         while(sum>=target &&i<=j)
         {
            mnlgth=min(mnlgth,j-i+1);
            cout<<mnlgth<<",";
            sum-=arr[i];
            i++;
         }

         j++;
       }

       if(mnlgth==INT_MAX) return 0;
       else return mnlgth;
    }
};