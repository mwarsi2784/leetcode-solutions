class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int top=-1;
        int bottom=10000;
        int left=10000;
        int right=-1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    top=max(top,i);
                    bottom=min(bottom,i);
                    left=min(left,j);
                    right=max(right,j);
                }
            }
        }
        return (right-left+1)*(top-bottom+1);
    }
};