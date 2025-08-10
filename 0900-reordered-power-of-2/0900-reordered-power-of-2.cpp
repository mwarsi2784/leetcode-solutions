class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s= to_string(n);
        sort(s.begin(),s.end());
        for(long long int i=1;i<=100000000000;i=i*2){
            string temp=to_string(i);
            sort(temp.begin(),temp.end());
            if(temp==s){
                return true;
            }
        }
        return false;
    }
};