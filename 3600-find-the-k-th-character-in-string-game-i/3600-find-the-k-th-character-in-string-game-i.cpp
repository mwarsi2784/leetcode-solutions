class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        while(word.size()<k){
            string temp=word;
            for(int i=0;i<temp.size();i++){
                if(temp[i]!='z' ) temp[i]=temp[i]+1;
                else{
                    temp[i]='a';
                }
            }
            word=word+temp;
        }
        return word[k-1];
    }
};