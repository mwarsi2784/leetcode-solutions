class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n-k+1,vector<int>(m-k+1,INT_MAX));
        for(int i=0;i<n-k+1;i++){
            for(int j=0;j<m-k+1;j++){
                vector<int> temp(k*k,0);
                for(int x=0;x<k;x++) for(int y=0;y<k;y++){
                    temp[k*x + y] = grid[i+x][j+y];
                }
                sort(temp.begin(),temp.end());
                int mn=INT_MAX;
                for(int z=0;z<temp.size()-1;z++){
                    if(abs(temp[z]-temp[z+1])!=0){
                        ans[i][j]=min(ans[i][j],abs(temp[z]-temp[z+1]));
                    }
                    cout<<temp[z]<<" ";
                }
                if(ans[i][j]==INT_MAX){
                    ans[i][j]=0;
                }
            }
        }
        return ans;
    }
};