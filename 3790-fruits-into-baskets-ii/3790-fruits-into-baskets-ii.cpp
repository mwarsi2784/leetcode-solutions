class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool> used(baskets.size(),false);
        int ans=0;
        for(int i=0;i<fruits.size();i++){
            int cant_placed=true;
            int j=0;
            while(j<baskets.size() && cant_placed){
                if(baskets[j]>=fruits[i]){
                    if(!used[j]){
                        cant_placed=false;
                        used[j]=true;
                    }
                }
                j++;
            }
            if(!cant_placed){
                ans++;
            }

        }
        return fruits.size()-ans;
    }
};