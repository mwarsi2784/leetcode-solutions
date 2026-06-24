class Solution {
public:
    int numSub(string s) {
        vector<int> one;
        int mod=1e9+7;
        long long ans=0;
        for(int i=0;i<s.size();i++){
            long long temp=0;
            while(i<s.size() && s[i]=='1') temp++,i++;
            if(temp!=0){
                cout<<temp<<" ";
                ans = (ans + temp*(temp+1)/2)%mod;
            }
        }
        return ans;

    }
};