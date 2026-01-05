class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int maxNeg=100000000;
        int negCount =0;
        long long sum=0;
        int zero=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                sum=sum+1ll*abs(matrix[i][j]);
                if(matrix[i][j]==0){
                    zero++;
                }
                if(matrix[i][j]<0){
                    negCount++;
                    maxNeg=min(maxNeg,abs(matrix[i][j]));
                }else{
                    maxNeg=min(maxNeg,matrix[i][j]);
                }
            }
        }
        if(zero>=1){
            return sum;
        }
        if(negCount%2){
            return sum-2*abs(maxNeg);
        }
        return sum;
    }
};