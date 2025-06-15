class Solution {
public:
    int maxDiff(int num) {
        string s=to_string(num);
        int n=s.size();
        string a=s;
        string b=s;
        int max_ind=0;
        int min_ind=0;
        while(max_ind<n-1 &&a[max_ind]=='9'){
            max_ind++;
        }
        for(int i=0;i<n;i++){
            if(a[i]==s[max_ind]){
                a[i]='9';
            }
        }
        cout<<a<<' '<<b;
        while(min_ind<n-1 && (s[min_ind]=='1' || s[min_ind]=='0')){
            min_ind++;
        }
        for(int i=0;i<n;i++){
            if(b[i]==s[min_ind] && s[min_ind]!=s[0]){
                b[i]='0';
            }
            else if(b[i]==s[min_ind]){
                b[i]='1';
            }
        }
        return stoi(a)-stoi(b);
    }
};