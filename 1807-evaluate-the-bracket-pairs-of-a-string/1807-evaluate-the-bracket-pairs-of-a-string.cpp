class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> know;
        for(int i=0;i<knowledge.size();i++){
            know[knowledge[i][0]]=knowledge[i][1];
        }
        int ansSize=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='('){
                ansSize++;
            }
            else{
                string temp="";
                i++;
                while(s[i]!=')'){
                    temp=temp+s[i];
                    i++;
                }
                if(know.contains(temp)){
                    ansSize=ansSize+know[temp].size();
                }
                else ansSize=ansSize+1;
            }
        }
        std::string ans(ansSize, ' ');
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]!='('){
                ans[j]=s[i];
                j++;
            }
            else{
                i++;
                string temp="";
                while(s[i]!=')'){
                    temp=temp+s[i];
                    i++;
                }
                if(know.contains(temp)){
                    string temp2=know[temp];
                    for(int k=0;k<temp2.size();k++){
                        ans[j]=temp2[k];
                        j++;
                    }
                }
                else{
                    ans[j]='?';
                    j++;
                }
            }
        }
        return ans;

    }
};