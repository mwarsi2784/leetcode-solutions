class Solution {
public:
    bool hasAllCodes(string s, int k) {
        map<string,int> seen;
        int req=(1<<k);
        if (s.size() < k) return false;
        for(int i=0;i<=s.size()-k;i++){
            string temp(k,'3');
            for(int j=0;j<k;j++){
                temp[j]=s[i+j];
            }
            if(seen[temp]==0){
                seen[temp]++;
                req--;
            }
        }
        if(req==0){
            return true;
        }
        return false;
    }
};