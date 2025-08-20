class Solution {

    bool fun(vector<vector<int>>& matrix, int k, int row, int col){
        for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
                if(matrix[i+row][j+col]==0){
                    return false;
                }
            }
        }
        return true;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==1){
                    for(int k=0;(k+i)<matrix.size() && (k+j)<matrix[i].size();k++){
                        if(fun(matrix,k,i,j)){
                            ans++;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};