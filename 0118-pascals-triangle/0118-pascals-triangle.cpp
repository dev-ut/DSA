class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
      // kepping the strcture 
      vector<vector<int>>fans;

      for(int i=0;i<n;i++)
      {
        vector<int>ans(i+1);
        fans.push_back(ans);
      }    
      // fillling 
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<=i;j++)
        {
            if(j==0 || j==i)
            {
                fans[i][j]=1;
            }
            else
            {
                fans[i][j]=fans[i-1][j-1]+fans[i-1][j];
            }

        }
      }
      return fans;
    }
};