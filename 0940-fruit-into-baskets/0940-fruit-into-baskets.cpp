class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int ans=1;
        int i=0;
        int j=0;
        set<int> unique;
        map<int,int> freq;
        unique.insert(fruits[i]);
        freq[fruits[i]]++;
        j++;
        while(j<n){
            unique.insert(fruits[j]);
            freq[fruits[j]]++;
            while(unique.size()>=3){
                freq[fruits[i]]--;
                if(freq[fruits[i]]<=0){
                    unique.erase(fruits[i]);
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};