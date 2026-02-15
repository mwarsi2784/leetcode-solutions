class Solution {
public:
    string addBinary(string a, string b) {
        string ans(max(a.size(),b.size()),'0');
        if(a.size()<b.size()){
           string temp(b.size()-a.size(),'0');
           a=temp+a;
        }
        if(b.size()<a.size()){
           string temp(a.size()-b.size(),'0');
           b=temp+b;
        }
        char carry='0';
        for(int i=a.size()-1;i>=0;i--){
            int temp=0;
            if(a[i]=='1') temp++;
            if(b[i]=='1') temp++;
            if(carry=='1') temp++;
            if(temp==3){
                ans[i]='1';
                carry='1';
            }
            else if(temp==2){
                ans[i]='0';
                carry='1';
            }
            else if(temp==1){
                ans[i]='1';
                carry='0';
            }
        }
        if(carry=='1'){
            return carry+ans;
        }
        return ans;
    }
};