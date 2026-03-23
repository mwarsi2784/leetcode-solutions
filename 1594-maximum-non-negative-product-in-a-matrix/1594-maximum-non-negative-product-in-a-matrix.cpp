class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int mod = 1e9+7;

        vector<vector<long long>> maxP(n, vector<long long>(m));
        vector<vector<long long>> minP(n, vector<long long>(m));

        maxP[0][0] = minP[0][0] = grid[0][0];

        for(int i=1;i<n;i++){
            maxP[i][0] = minP[i][0] = maxP[i-1][0] * grid[i][0];
        }

        for(int j=1;j<m;j++){
            maxP[0][j] = minP[0][j] = maxP[0][j-1] * grid[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                long long a = maxP[i-1][j] * grid[i][j];
                long long b = minP[i-1][j] * grid[i][j];
                long long c = maxP[i][j-1] * grid[i][j];
                long long d = minP[i][j-1] * grid[i][j];

                maxP[i][j] = max({a,b,c,d});
                minP[i][j] = min({a,b,c,d});
            }
        }

        long long ans = maxP[n-1][m-1];
        if(ans < 0) return -1;
        return ans % mod;
    }
};