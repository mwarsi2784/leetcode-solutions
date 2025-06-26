class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                ans++;
            }
        }
        long long num=0;
        long long pow=1;
        for(int i=s.size()-1;i>=0 && num<k && pow<=k;i--){
            if(s[i]=='1'){
                if(num+pow<=k){
                    num+=pow;
                    ans++;
                }
                else{
                    break;
                }
            }
            pow=pow*2;
        }
        return ans;
    }
};