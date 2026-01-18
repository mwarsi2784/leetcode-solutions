class Solution {
public:
    int fun(int row,int col, int size,vector<vector<int>>& grid ){
        int ans=0;
        int diag=0;
        int diag2=0;
        for(int i=0;i<size;i++){
            diag=diag+grid[row+i][col+i];
            diag2=diag2+grid[row+i][col-i+size-1];
        }
        if(diag!=diag2){
            cout<<row<<" "<<col<<" "<<diag<<" "<<diag2<<"\n";
            return 0;
        }
        for(int i=0;i<size;i++){
            int rowSum=0;
            int colSum=0;
            for(int j=0;j<size;j++){
                rowSum=rowSum+grid[row+i][col+j];
                colSum=colSum+grid[row+j][col+i];
            }
            if(rowSum!=colSum || rowSum!=diag){
                cout<<row<<" "<<col<<" "<<diag<<" "<<diag2<<"\n";
                return 0;
            }
        }
        //cout<<row<<" "<<col<<" "<<diag<<" "<<diag2<<"\n";
        return 1;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                for(int k=1;k+i<grid.size()+1 && k+j<grid[i].size()+1;k++){
                    if(fun(i,j,k,grid)){
                        ans=max(ans,k);
                    }
                }
            }
        }
        return ans;
    }
};