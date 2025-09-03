class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
     {
         // 1 transpose the matrix
           int n=matrix.size();   // n=m
        //int m=matrix[0].size();
        // vector<vector<int>>ans(m,vector<int>(n,0));  //yaad rkhna jahan 2d vector ho to 
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)  // very imp
            {
               // matrix[j][i]=matrix[i][j]; we cant do this coz if we do this then values for prceeding operations will gey altered

               //so swap
               int temp=matrix[i][j];
               matrix[i][j]=matrix[j][i];
               matrix[j][i]=temp;
            }
        }
        // reverse each row which is swapping only

            for(int r=0;r<n;r++)  // traversing in entire matrix k denoting here row no
            {
                // now as we do reverse in array keeping i at 0 and j at n-1 index fro every coloumn 
                int i=0;
                int j=n-1;
                while(i<=j)
                {
                    int temp = matrix[r][i];
                    matrix[r][i]=matrix[r][j];
                    matrix[r][j]=temp;
                    i++;
                    j--;
                }
            }
            return;
    }
};