class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans(spells.size(),0);
        for(int i=0;i<spells.size();i++){
            long long num=((success+spells[i]-1)/spells[i]);
            long long count = potions.end()- upper_bound(potions.begin(),potions.end(),num-1);
            ans[i]=count;
        }
        return ans;
    }
};