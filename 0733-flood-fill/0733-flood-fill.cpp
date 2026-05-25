class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int r=image.size();
        int c=image[0].size();
        int org_clr=image[sr][sc]; // so that we can keep a track of orgional color
        if(color==org_clr) return image;

        queue<pair<int ,int>>q;
        // cahnge the color of this cell to annewn color 
        image[sr][sc]=color;
        q.push({sr,sc});

        while(q.size()>0)
        {
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                auto[row,col]=q.front();
                q.pop();

                // move in all 4 directionsif the cell is having the same colr as orgional color transform 
                // up 
                if(row-1>=0 && image[row-1][col]==org_clr)
                {
                    image[row-1][col]=color;
                    q.push({row-1,col});
                }
                // down 
                if(row+1<r && image[row+1][col]==org_clr)
                {
                    image[row+1][col]=color;
                    q.push({row+1,col});
                }
                //left
                if(col-1>=0 && image[row][col-1]==org_clr)
                {
                    image[row][col-1]=color;
                    q.push({row,col-1});
                }
                //right
                if(col+1<c && image[row][col+1]==org_clr)
                {
                    image[row][col+1]=color;
                    q.push({row,col+1});
                }
            }
        }
        return image;
    }
};