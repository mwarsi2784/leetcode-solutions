class Solution {
public:
    int minimumDeletions(string s) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int ans=0;
        int bCount=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b') bCount++;
            if(s[i]=='a'){
                if(bCount>0){
                    ans++;
                    bCount--;
                }
            }
        }
        return ans;
    }
};