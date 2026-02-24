class Solution {
public:
void dfs(vector<vector<int>>& isConnected, int row,vector<bool>&visited)
{
    visited[row]=true;  // vsisted ark kiya 
    // ab is row ke uske adj directly connetd elmts ko visite kro 
    for(int col=0;col<isConnected.size();col++)
    {
        if(isConnected[row][col]==1 && visited[col]==false)
        {
            // to call rec and visit
            dfs(isConnected,col,visited);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size();
        int countOfPrv=0;

        vector<bool>visited(n,false); // 

        for(int i=0;i<n;i++)
        {
            if(visited[i]== false)
            {
              dfs(isConnected,i,visited);  // jaise hi eak row mark ho
               countOfPrv++;
            }
        }
        return countOfPrv;
    }
};