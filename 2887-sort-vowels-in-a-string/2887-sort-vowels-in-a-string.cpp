class Solution {

// Function to check whether a
// character is vowel or not
bool fun(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o'
        || x == 'u' || x == 'A' || x == 'E' || x == 'I'
        || x == 'O' || x == 'U')
        return true;
    else
        return false;
}
public:
    string sortVowels(string s) {
        vector<char> temp(s.size());
        vector<char> vowel;
        for(int i=0;i<s.size();i++){
            if(fun(s[i])){
                vowel.push_back(s[i]);
                temp[i]='1';
            }else{
                temp[i]=s[i];
            }
        }
        sort(vowel.begin(),vowel.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            if(temp[i]=='1'){
                temp[i]=vowel[j];
                j++;
            }
        }
        string ans(s.size(),'o');
        for(int i=0;i<s.size();i++){
            ans[i]=temp[i];
        }
        return ans;
    }
};