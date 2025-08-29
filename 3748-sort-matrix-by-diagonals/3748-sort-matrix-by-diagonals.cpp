class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int k=0;k<=9;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i<n-1 && j<n-1 && i>=j){
                        if(grid[i][j]<grid[i+1][j+1]){
                            swap(grid[i][j],grid[i+1][j+1]);
                        }
                    }
                    if(i<n-1 && j<n-1 && i<j){
                        if(grid[i][j]>grid[i+1][j+1]){
                            swap(grid[i][j],grid[i+1][j+1]);
                        }
                    }
                }
            }
        }
        return grid;
    }
};