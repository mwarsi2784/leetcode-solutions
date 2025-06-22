class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        vector<string> ans((n+k-1)/k);
        for(int i=0;i<ans.size();i++){
            int j=i*k;
            int c=0;
            string temp(k,' ');
            while(c<k){
                if(c+j>=n){
                    temp[c]=fill;
                }else{
                    temp[c]=s[j+c];
                }
                c++;
            }
            ans[i]=temp;
        }
        return ans;
    }
};