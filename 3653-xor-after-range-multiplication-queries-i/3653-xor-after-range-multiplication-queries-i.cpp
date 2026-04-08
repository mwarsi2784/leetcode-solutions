class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod=1e9+7;
        for(int i=0;i<queries.size();i++){
            for(int j=queries[i][0];j<=queries[i][1];j+=queries[i][2]){
                long long temp=(1ll*nums[j]*queries[i][3])%mod;
                nums[j]=temp;
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};