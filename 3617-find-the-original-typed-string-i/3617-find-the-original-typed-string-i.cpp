class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size();
        vector<int> con;
        int i=0;
        while(i<n){
            char temp=word[i];
            int c=0;
            while(temp==word[i]){
                i++;
                c++;
            }
            if(c>1){
                con.push_back(c);
            }
        }
        int ans=1;
        for(int i=0;i<con.size();i++){
            int temp=con[i]-1;
            ans=ans+temp;
        }
        return ans;
    }
};