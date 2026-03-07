class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        int ans[2]={0,0};
        for(int i=0;i<n;++i){
            ans[(s[i]^i)&1]++;
        }
        int res = min(ans[0],ans[1]);
        for(int i=0;i<n;++i){
            ans[(s[i]^i)&1]--;
            ans[(s[i]^(n+i))&1]++;
            res=min(res,min(ans[0],ans[1]));
        }
        return res;
    }
};