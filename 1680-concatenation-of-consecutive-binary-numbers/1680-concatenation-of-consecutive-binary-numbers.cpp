class Solution {
public:
    int concatenatedBinary(int n) {
        int bitCount=0;
        long long ans=0;
        int mod=1e9+7;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0){
                bitCount++;
            }
            ans<<=bitCount;
            ans=( ans | i )%mod;
        }
        return ans;
    }
};