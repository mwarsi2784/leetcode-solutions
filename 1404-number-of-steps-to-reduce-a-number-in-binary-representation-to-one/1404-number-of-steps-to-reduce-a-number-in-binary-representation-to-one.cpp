class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        int carry=0;
        for(int i=s.size()-1;i>=1;i--){
            if(carry>0){
                if(s[i]=='1'){
                    s[i]='0';
                }else if(s[i]=='0'){
                    s[i]='1';
                    carry--;
                }
            }
            if(s[i]=='1'){
                ans+=2;
                carry++;
            }else{
                ans+=1;
            }
        }
        return ans+carry;
    }
};
