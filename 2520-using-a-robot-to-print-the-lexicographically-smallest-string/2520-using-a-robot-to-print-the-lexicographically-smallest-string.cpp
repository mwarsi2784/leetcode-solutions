class Solution {
public:
    string robotWithString(string s) {
        map<int,int> f;
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            f[s[i]]++;
        }
        string ans;
        char c='a';
        for(int i=0;i<s.size();++i){
            stk.emplace(s[i]);
            f[s[i]]--;
            while(c!='z' && f[c]==0){
                c++;
            }
            while(!stk.empty() && stk.top()<=c){
                ans.push_back(stk.top());
                stk.pop();
            }
        }
        return ans;
    }
};