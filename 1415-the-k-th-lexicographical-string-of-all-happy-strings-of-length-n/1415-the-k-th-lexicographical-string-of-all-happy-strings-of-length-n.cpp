class Solution {
    vector<string> fun(int n){
        if(n==1){
            return {"a","b","c"};
        }
        vector<string> temp = fun(n-1);
        int len = 3*(1<<(n-1));
        vector<string> ans(len,"");
        int j=0;
        for(char i='a';i<='c';i++){
            for(int k=0;k<temp.size();k++){
                if(temp[k][0]!=i){
                    ans[j++] = i+temp[k];
                }
            }
        }
        return ans;
    }
public:
    string getHappyString(int n, int k) {
        int len = 3*(1<<(n-1));
        if(k>len){
            return "";
        }
        vector<string> ans;
        ans=fun(n);
        return ans[k-1];
    }
};