class Solution {
public:
    int maxIceCream(vector<int>& s, int coins) {
        sort(s.begin(),s.end());
        int ans=0;
        int n=s.size();
        int ret=0;
        for(int i=0;i<n;i++){
            if(ans+s[i]<=coins){
                ans+=s[i];
                ret++;
            }
        }
        return ret;
    }
};