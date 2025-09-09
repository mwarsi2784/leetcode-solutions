class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1,0);
        dp[1]=1;
        int mod=1e9+7;
        long long canShare=0;
        for(int i=2;i<=n;i++){
            if(i-delay>=1){
                canShare=(canShare+dp[i-delay]+mod)%mod;
            }
            if(i-forget>=1){
                canShare=(canShare-dp[i-forget]+mod)%mod;
            }
            dp[i]=canShare;
        }
        long long ans=0;
        for(int i=n-forget+1;i<=n;i++){
            ans=(ans+dp[i])%mod;
        }
        return ans;

    }
};