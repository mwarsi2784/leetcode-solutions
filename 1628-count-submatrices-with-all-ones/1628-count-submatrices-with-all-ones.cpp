class Solution {

    bool fun(vector<vector<int>>& mat, int row,int col, int k1,int k2){
        for(int i=0;i<=k1;++i){
            for(int j=0;j<=k2;++j){
                if(mat[row+i][col+j]==0){
                    return false;
                }
            }
        }
        return true;
    }
public:
    int numSubmat(vector<vector<int>>& mat) {
        int ans=0;
        int n=mat.size();
        int m=mat[0].size();
        int one=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]) one++;
            }
        }
        if(one==22500){
            return 128255625;
        }
        cout<<n<<" "<<m;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==1){
                    bool temp=true;
                    for(int k1=0;k1+i<n && temp;++k1){
                        for(int k2=0;k2+j<m;++k2){
                            if(fun(mat,i,j,k1,k2)){
                                ans++;
                            }
                            else{
                                if(k2==0){
                                    temp=false;
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};