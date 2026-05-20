class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n=b.size();
        vector<int> c(n,0);
        unordered_map<int,int> f;
        int ans=0;
        for(int i=0;i<n;i++){
            int a1=a[i];
            int b1=b[i];
            if(f[a1]==2){
                f[a1]=3;
                ans++;
            }
            if(f[a1]==0){
                f[a1]=1;
            }
            if(f[b1]==1){
                f[b1]=3;
                ans++;
            }
            if(f[b1]==0){
                f[b1]=2;
            }
            c[i]=ans;
        }
        return c;
    }
};