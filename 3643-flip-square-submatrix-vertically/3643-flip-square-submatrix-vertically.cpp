class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int topRow=x;
        int bottomRow=x+k-1;
        while(topRow<bottomRow){
            for(int i=y;i-y<k;i++){
                swap(grid[topRow][i],grid[bottomRow][i]);
            }
            topRow++;
            bottomRow--;
        }
        return grid;
    }
};