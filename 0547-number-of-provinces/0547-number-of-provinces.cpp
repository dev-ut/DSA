class Solution {
public:
void bfs(vector<vector<int>>& isConnected, int node, vector<bool>& visited)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int curr = q.front();   // alag naam, shadowing nahi
        q.pop();

        for (int col = 0; col < isConnected.size(); col++)
        {
            if (isConnected[curr][col] == 1 && !visited[col])
            {
                visited[col] = true;
                q.push(col);
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) 
{
    int n = isConnected.size();
    int countOfPrv = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(isConnected, i, visited);
            countOfPrv++;   // ek BFS = ek province
        }
    }
    return countOfPrv;
}
};