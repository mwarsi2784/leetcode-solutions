class Solution {
public:
    bool isValid(string word) {
        if(word.size()<=2){
            return false;
        }
        bool isVowel=false;
        bool isConsonent=false;
        bool isDigit=false;
        for(int i=0;i<word.size();i++){
            if(word[i]>='0' && word[i]<='9'){
                isDigit=true;
            }
            else if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u' || word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U'){
                isVowel=true;
            }
            else if((word[i]>='A' && word[i]<='Z') || (word[i]>='a' && word[i]<='z')){
                isConsonent=true;
            }
            else{
                return false;
            }
        }

        if(isVowel && isConsonent){
            return true;
        }
        return false;
    }
};