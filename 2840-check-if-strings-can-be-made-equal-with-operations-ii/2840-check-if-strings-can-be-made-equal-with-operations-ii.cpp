class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        string s1even(n/2+(n&1),'.');
        string s2even(n/2+(n&1),'.');
        string s1odd(n/2,',');
        string s2odd(n/2,',');
        int odd=0;
        int even=0;
        for(int i=0;i<n;i++){
            if(i&1){
                s1odd[odd]=s1[i];
                s2odd[odd]=s2[i];
                odd++;
            }else{
                s1even[even]=s1[i];
                s2even[even]=s2[i];
                even++;
            }
        }
        sort(s1even.begin(),s1even.end());
        sort(s2even.begin(),s2even.end());
        sort(s1odd.begin(),s1odd.end());
        sort(s2odd.begin(),s2odd.end());

        return (s1even==s2even) && (s1odd==s2odd);
    }
};