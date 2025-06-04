class Solution {
public:
    string answerString(string s, int numFriends) {
        if(numFriends==1){
            return s;
        }
        int n=s.size();
        int len=n-numFriends+1;
        char mx='a';
        for(int i=0;i<n;i++){
            mx=max(mx,s[i]);
        }
        vector<int> mxi;
        for(int i=0;i<n;i++){
            if(s[i]==mx){
                mxi.push_back(i);
            }
        }
        string ans="a";
        for(int i=0;i<mxi.size();i++){
            ans = std::max(ans, s.substr(mxi[i], std::min<size_t>(len, s.length() - mxi[i])));
        }
        return ans;
    }
};