class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mod=1e9+7;
        vector<vector<long long>> maxP(n,vector<long long>(m,1));
        vector<vector<long long>> minP(n,vector<long long>(m,1));
        maxP[0][0]=minP[0][0]=grid[0][0];

        for(int i=1;i<n;i++){
            maxP[i][0]=maxP[i-1][0]*grid[i][0];
            minP[i][0]=minP[i-1][0]*grid[i][0];
        }
        for(int i=1;i<m;i++){
            maxP[0][i]=maxP[0][i-1]*grid[0][i];
            minP[0][i]=minP[0][i-1]*grid[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                long long a = maxP[i-1][j]*grid[i][j];
                long long b = minP[i-1][j]*grid[i][j];
                long long c = maxP[i][j-1]*grid[i][j];
                long long d = minP[i][j-1]*grid[i][j];
                maxP[i][j]=max({a,b,c,d});
                minP[i][j]=min({a,b,c,d});
            }
        }
        int prod = 1ll*(maxP[n-1][m-1])%mod;
        return prod<0?-1:prod;
    }
};