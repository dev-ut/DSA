class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>>fans;
        

        // now we will first preapre the skeleton than fill 
        for(int i=0;i<n;i++)
        {
          vector<int>ans(i+1);
          fans.push_back(ans);
        }
        // now fill the structure 

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
               if(j==0 || j==i) fans[i][j]=1;
               else fans[i][j]=fans[i-1][j-1]+fans[i-1][j];
            }
        }
       return fans;
    }
};