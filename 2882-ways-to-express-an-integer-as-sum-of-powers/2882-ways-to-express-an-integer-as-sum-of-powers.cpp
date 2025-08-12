class Solution {

int fun(vector<long long> &coins, vector<int> &dp, int target) {
    int mod= 1e9+7;
    for (int coin : coins) {
        for (int sum = target; sum >= coin; --sum) {
            dp[sum] = (dp[sum] + dp[sum - coin])%mod;
        }
    }
    return dp[target];
}


public:
    int numberOfWays(int n, int x) {
        vector<long long> coins;
        for(int i=1;i<=n;i++){
            if(pow(i,x)<=n){
                coins.push_back(pow(i*1ll,x*1ll));
            }
            else{
                break;
            }
        }
        vector<int> dp(n+1,0);
        dp[0]=1;
        fun(coins,dp,n);
        return dp[n];
    }
};