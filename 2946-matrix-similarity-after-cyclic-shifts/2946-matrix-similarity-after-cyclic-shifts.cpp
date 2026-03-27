class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k=k%m;
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i&1){
                    int newInd = (j-k+m)%m;
                    ans[i][newInd]=mat[i][j];
                }
                else{
                    int newInd = (j+k)%m;
                    ans[i][newInd]=mat[i][j];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=ans[i][j]) return false;
            }
        }
        return true;
        
    }
};