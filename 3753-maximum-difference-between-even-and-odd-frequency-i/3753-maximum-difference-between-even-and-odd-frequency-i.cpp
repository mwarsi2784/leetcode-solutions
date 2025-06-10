class Solution {
public:
    int maxDifference(string s) {
        map<int,int> f;
        int mxo=0;
        int mne=1000000;
        for(int i=0;i<s.size();++i){
            f[s[i]]++;

        }
        for(char i='a';i<='z';i++){
            if(f[i]&1){
                mxo=max(mxo,f[i]);
            }else if(f[i]!=0){
                mne=min(mne,f[i]);
            }
        }
        return mxo-mne;
    }
};