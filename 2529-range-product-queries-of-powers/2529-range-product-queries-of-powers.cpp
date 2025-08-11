class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int sum=0;
        for(int i=0;i<31;i++){
            if( n & (1<<i) ){
                powers.push_back(1<<i);
            }
        }
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int prod=1;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                int mod=1e9+7;
                prod=(1ll*prod*powers[j])%(mod);
                ans[i]=prod;
            }
        }
        return ans;
    }
};