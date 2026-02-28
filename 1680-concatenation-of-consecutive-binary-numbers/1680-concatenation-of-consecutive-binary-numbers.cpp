long long dp[100001]={0};
int last=1;
class Solution {
public:
    int concatenatedBinary(int n) {
        int bitCount=0;
        long long ans=dp[last-1];
        if(dp[n]!=0){
            return dp[n];
        }
        int mod=1e9+7;
        for(int i=last;i<=n;i++){
            bitCount=32-__builtin_clz(i);
            ans<<=bitCount;
            ans=( ans | i )%mod;
            dp[i]=ans;
        }
        last=n;
        return ans;
    }
};