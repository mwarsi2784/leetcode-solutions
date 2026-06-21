class Solution {
public:
    int maxIceCream(vector<int>& s, int coins) {
        sort(s.begin(),s.end());
        int ans=0;
        int ret=0;
        int n=s.size();
        int mx=0;
        vector<long long> freq(100000+1,0);
        for(int i=0;i<n;i++){
            mx=max(mx,s[i]);
            freq[s[i]]++;
        } 
        for(int i=1;i<=mx;i++){
            if(ans+i>coins){
                return ret;
            }
            if(ans+freq[i]*i<=coins){
                ans=ans+freq[i]*i;
                ret=ret+freq[i];
            }else{
                int diff=coins-ans;
                ret=ret+diff/i;
                ans=ans+ret*i;
            }
        }
        return ret;
    }
};