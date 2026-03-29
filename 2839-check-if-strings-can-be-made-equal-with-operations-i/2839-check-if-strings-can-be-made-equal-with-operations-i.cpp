class Solution {
    bool fun(string s1,string s2){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1==s2){
            return true;
        }
        return false;
    }
public:
    bool canBeEqual(string s1, string s2) {
        string s1even=string(1,s1[0])+s1[2];
        string s1odd=string(1,s1[1])+s1[3];
        string s2even=string(1,s2[0])+s2[2];
        string s2odd=string(1,s2[1])+s2[3];
        return fun(s1even,s2even) && fun(s2odd,s1odd);
    }
};