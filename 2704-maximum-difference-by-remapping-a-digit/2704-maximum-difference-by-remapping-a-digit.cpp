class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        string mx=s;
        string mn=s;
        int max_ind=0;
        int min_ind=0;
        while(max_ind<s.size()-1 && s[max_ind]=='9'){
            max_ind++;
        }
        while(min_ind<s.size()-1 && s[min_ind]=='0'){
            min_ind++;
        }

        for(int i=0;i<s.size();i++){
            if(s[i]==s[max_ind]){
                mx[i]='9';
            }
            if(s[i]==s[min_ind]){
                mn[i]='0';
            }
        }
        int ans=stoi(mx)-stoi(mn);
        return ans;
    }
};
