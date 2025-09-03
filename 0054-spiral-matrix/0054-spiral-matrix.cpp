class Solution {
public:
   vector<int> spiralOrder(vector<vector<int>>& matrix) 
   {
    vector<int> ans;
    int r = matrix.size();
    int c = matrix[0].size();

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right) 
    {
        //left to right
        for (int i = left; i <= right; i++) 
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        //  top to bottom
        for (int i = top; i <= bottom; i++) 
        {
            ans.push_back(matrix[i][right]);
            cout<<"ye chlA";
        }
        right--;

        //  right to left (check if top <= bottom again)
         if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
         }

        // bottom to top (check if left <= right again)
         if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

};