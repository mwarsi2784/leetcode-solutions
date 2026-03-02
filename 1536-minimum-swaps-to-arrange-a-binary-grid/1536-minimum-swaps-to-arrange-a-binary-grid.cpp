class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> zeroArr(n,0);
        for(int i=0;i<n;i++){
            int j=n-1;
            int zero=0;
            while(j>=0 && grid[i][j]==0){
                j--;
                zero++;
            }
            zeroArr[i]=zero;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int req = n-i-1;
            if(req<=zeroArr[i]){
                continue;
            }
            int j=i+1;
            while(j<n && zeroArr[j]<req ){
                j++;
            }
            if(j==n){
                return -1;
            }
            for(;j>i;){
                swap(zeroArr[j],zeroArr[--j]);
                ans++;
            }
        }
        return ans;
    }
};