class Solution {
public:
    int n;
 
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        int sum=accumulate(piles.begin(),piles.end(),0);

      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      for(int i=n-1;i>=0;i--){
        for(int m=n;m>=1;m--){
            int ans=INT_MIN;
            int sum=0;
            for(int x=1;x<=2*m;x++){
                int idx=i+x-1;
                if(idx>=n) break;
                sum+=piles[idx];
                ans=max(ans,sum-dp[idx+1][max(x,m)]);
            }
            dp[i][m]=ans;
        }
      }
      int ans=dp[0][1];
      return (ans+sum)>>1;
      
    }
};