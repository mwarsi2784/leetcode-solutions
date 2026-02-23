class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> f;
        if (s.size() < k) return false;
        for(int i=0;i<=s.size()-k;i++){
            string temp(k,'3');
            for(int j=0;j<k;j++){
                temp[j]=s[i+j];
            }
            f.insert(temp);
        }
        if(f.size()==(1<<k)){
            return true;
        }
        return false;
    }
};