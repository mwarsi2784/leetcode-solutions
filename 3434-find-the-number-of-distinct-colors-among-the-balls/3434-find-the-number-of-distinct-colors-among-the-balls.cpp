class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> color_to_limit,limit_to_color;
        set<int> s;
        vector<int> ans(queries.size());
        int count=0;
        for(int i=0;i<queries.size();i++){
            int limit=queries[i][0];
            int color=queries[i][1];
            if(s.find(limit)==s.end()){
                s.insert(limit);
                color_to_limit[color]++;
                limit_to_color[limit]=color;
                if(color_to_limit[color]==1){
                    count++;
                }
            }else{
                color_to_limit[limit_to_color[limit]]--;
                if(color_to_limit[limit_to_color[limit]]==0){
                    count--;
                }
                color_to_limit[color]++;
                limit_to_color[limit]=color;
                if(color_to_limit[color]==1){
                    count++;
                }
            }
            ans[i]=count;
        }
        return ans;
    }
};