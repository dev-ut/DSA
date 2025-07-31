class Solution {
public:
    int n;

    bool canreach(vector<vector<int>>& grid, int r, int c, int time, vector<vector<int>>& visited) 
    {
        // base conditions
        if (r < 0 || c < 0 || r >= n || c >= n)
        {
            return false;  // out of bound cases
        } 
        if(visited[r][c]==1) return false ;  // already visited

        if (grid[r][c] > time) return false;

        if (r == n - 1 && c == n - 1) return true;

        visited[r][c] = 1;

        // 4 directions me try karo
        if (canreach(grid, r + 1, c, time, visited)) return true; // Down
        if (canreach(grid, r - 1, c, time, visited)) return true; // Up
        if (canreach(grid, r, c + 1, time, visited)) return true; // Right
        if (canreach(grid, r, c - 1, time, visited)) return true; // Left
        

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) 
    {
        n = grid.size();
        int lo = 0;
        int hi = n * n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            vector<vector<int>> visited(n, vector<int>(n, 0));

            if (canreach(grid, 0, 0, mid, visited)) {
                // aur kam time me pahuch sakte ho kya
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
