class Solution {
    int fun(vector<vector<int>>& matrix, int row, int col){
        int k=0;
        for(k=0;row+k<matrix.size() && k+col<matrix[0].size();k++){
            for(int i=0;i<=k;i++){
                if(matrix[row+i][col+k]==0){
                    return k;
                }
            }
            for(int i=0;i<=k;i++){
                if(matrix[row+k][col+i]==0){
                    return k;
                }
            }
        }
        return k;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==1){
                    int len=fun(matrix,i,j);
                    ans=ans+len;
                }
            }
        }
        return ans;
    }
};