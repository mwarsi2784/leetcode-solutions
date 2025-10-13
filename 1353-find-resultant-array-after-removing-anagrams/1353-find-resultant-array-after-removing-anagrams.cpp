class Solution {
public:
    string fun(string s){
        sort(s.begin(),s.end());
        return s;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        for(int i=0;i<words.size();){
            string curr=words[i];
            ans.push_back(words[i]);
            sort(curr.begin(),curr.end());
            while(i<words.size() && curr==fun(words[i])){
                i++;
            }

        }
        return ans;
    }
};