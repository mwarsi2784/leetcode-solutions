class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<long long> col(m,0),row(n,0);
        long long total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i]=row[i]+1ll*grid[i][j];
                col[j]=col[j]+1ll*grid[i][j];
                total+=(1ll*grid[i][j]);
            }
        }
        long long sum=0;
        for(int i=0;i<n-1;i++){
            sum=sum+row[i];
            if(sum==total-sum){
                return true;
            }
        }
        sum=0;
        for(int i=0;i<m-1;i++){
            sum=sum+col[i];
            if(sum==total-sum){
                return true;
            }
        }
        return false;
    }
};