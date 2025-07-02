class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
      int n=code.size();
      vector<int>ans(n,0);

         for(int i=0;i<n;i++)
         {
            int sum=0;

            if(k>0)
            {
            int j=i+1;
            int count=0;

            while(count<k)
            {
                 j = j % n; // circular bana diya
                sum=sum+code[j];

                j++;
                count++;
            }

            ans[i]=sum;
         }
      
      else if(k<0)
      {
            int j=i+n-1;  // 3 pr khada kiya j ko for last elemnt sum
            int count=0;

            while(count<abs(k))
            {
                 j = (j+n) % n; // circular bana diya  and 3 index pr aya
                sum=sum+code[j];

                j--;
                count++;
            }

            ans[i]=sum;
      }

    }

      return ans;
    }
};