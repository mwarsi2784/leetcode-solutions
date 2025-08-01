class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        vector<int> prev(1);
        prev[0]=1;
        ans[0]=prev;
        for(int i=1;i<numRows;i++){
            vector<int> curr(i+1,1);
            for(int j=1;j<i;j++){
                curr[j]=prev[j-1]+prev[j];
            }
            ans[i]=curr;
            prev=curr;
        }
        return ans;
    }
};