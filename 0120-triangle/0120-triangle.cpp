class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size());
        for(int i=0;i<triangle.size();i++){
            dp[i].resize(triangle[i].size(),0);
        }
        for(int i=0;i<triangle.size();i++){
            if(i==0){
                dp[i][0]=triangle[0][0];
                continue;
            }
            for(int j=0;j<triangle[i].size();j++){
                if(j==0){
                    dp[i][j]=triangle[i][j]+dp[i-1][j];
                }else if(j==triangle[i].size()-1){
                    dp[i][j]=triangle[i][j]+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=triangle[i][j]+min(dp[i-1][j-1],dp[i-1][j]);
                }
            }
        }
        int ans=1000000000;
        for(int j=0;j<triangle[triangle.size()-1].size();j++){
            int i=triangle.size()-1;
            ans=min(ans,dp[i][j]);
        }
        return ans;
    }
};