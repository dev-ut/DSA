class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        int r = mat.size();
        int c = mat[0].size();
        
        // step 1: sabhi diagonals store karo map me
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                mp[i + j].push_back(mat[i][j]); // diagonal key = i + j  ... vector min push kr diya
            }
        }
        
        vector<int> ans;
        
        // step 2: diagonals ko final vector me daalo by traversing till the no of keys and how will get it by r+c-1
        for(int k = 0; k < r + c - 1; k++) 
        {
            if(k % 2 == 0) {
                // even diagonal => reverse order
                reverse(mp[k].begin(), mp[k].end());
            }
            for(int val : mp[k]) {
                ans.push_back(val);
            }
        }
        
        return ans;
    }
};
