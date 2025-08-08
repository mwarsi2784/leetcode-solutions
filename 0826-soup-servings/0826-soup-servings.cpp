double fun(int a, int b, vector<vector<double>> &dp){
    if(a<=0 && b<=0) return 0.5;
    if(a<=0) return 1;
    if(b<=0) return 0;
    if(dp[a][b]!=-1){
        return dp[a][b];
    }
    double ans;
    ans=0.25*(fun(a-4,b,dp)+fun(a-3,b-1,dp)+fun(a-2,b-2,dp)+fun(a-1,b-3,dp));
    dp[a][b]=ans;
    return ans;
}

class Solution {
public:
    double soupServings(int n) {
        if(n>=5000){
            return 1.0;
        }
        n=(n+24)/25;
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1.0));
        return fun(n,n, dp);
    }
};