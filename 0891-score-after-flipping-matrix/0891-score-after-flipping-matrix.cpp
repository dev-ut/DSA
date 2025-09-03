class Solution {
public:
    int matrixScore(vector<vector<int>>& mat) 
    {
     int r=mat.size();
     int c=mat[0].size();
     // step 1 is to flip the row if the starting value of the coloummn is 0 coz we know most siginifiact left bit will hold highest value 

     for(int i=0;i<r;i++)
     {
        if(mat[i][0]==0)     // that is agr colm ki first value is 0 then chnge to 1 wherver 1 is 0
        {
            for(int j=0;j<c;j++)
            {
                   if(mat[i][j]==0) mat[i][j]=1;
                   else mat[i][j]=0;
            }
        }
     }
     //step 2 is to know that if the no of zero is greater than 1 in colmn it will lower thecommnse of  higher value no 
    

     for(int j=0;j<c;j++)
     {
         int noz=0,noo=0;
        for(int i=0;i<r;i++)
        {
           if(mat[i][j]==0) noz++;
           else noo++;
        }

        if(noz>noo)
        {
            for(int i=0;i<r;i++)
            { 
                mat[i][j]=(mat[i][j]==0)?1:0;

            }
            
        }
     }
     //step 3 is to chnage the binary data in to decimal form 
     int sum=0;
     for(int i =0;i<r;i++)
     {
        int x=1;//// andr isliye coz we r solving for evry coloumn 
        for(int j=c-1;j>=0;j--)
        {
            sum=sum+mat[i][j]*x;
            x=x*2;
        }
     }
     return sum;      
        
    }
};