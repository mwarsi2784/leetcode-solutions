class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        long long ans=0;
        set<int> boxes,key,visited,can_open;
        for(int i=0;i<status.size();i++){
            if(status[i]==1){
                key.insert(i);
            }
        }
        for(int i=0;i<initialBoxes.size();i++){
            boxes.insert(initialBoxes[i]);
            if(key.find(initialBoxes[i])!=key.end()){
                can_open.insert(initialBoxes[i]);
            }
        }
        
        while(!can_open.empty()){
            int lab= *can_open.begin();
            if(visited.find(lab)!=visited.end()){
                can_open.erase(lab);
                continue;
            }
            can_open.erase(lab);
            visited.insert(lab);
            ans=ans+candies[lab]*1ll;
            for(int i=0;i<keys[lab].size();i++){
                key.insert(keys[lab][i]);
                if(boxes.find(keys[lab][i])!=boxes.end()){
                    can_open.insert(keys[lab][i]);
                }
            }
            for(int i=0;i<containedBoxes[lab].size();i++){
                boxes.insert(containedBoxes[lab][i]);
                if(status[containedBoxes[lab][i]]==1){
                    can_open.insert(containedBoxes[lab][i]);
                }else if(key.find(containedBoxes[lab][i])!=key.end()){
                    can_open.insert(containedBoxes[lab][i]);
                }
            }
        }
        return ans;
    }
};