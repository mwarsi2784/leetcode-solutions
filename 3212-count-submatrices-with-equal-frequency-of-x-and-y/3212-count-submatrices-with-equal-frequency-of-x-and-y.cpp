class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> x(n+1,vector<int>(m+1,0));
        vector<vector<int>> y(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                x[i+1][j+1]=x[i][j+1]+x[i+1][j]-x[i][j]+(grid[i][j]=='X');
                y[i+1][j+1]=y[i][j+1]+y[i+1][j]-y[i][j]+(grid[i][j]=='Y');
                if(x[i+1][j+1]>0){
                    if(x[i+1][j+1]==y[i+1][j+1]) ans++;
                }
            }
        }
        return ans;
    }
};