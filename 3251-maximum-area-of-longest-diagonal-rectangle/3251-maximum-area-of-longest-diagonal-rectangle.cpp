
class Solution {
    
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        vector<pair<int,int>> a(dimensions.size());
        for(int i=0;i<dimensions.size();i++){
            int diag=dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1];
            int area=dimensions[i][0]*dimensions[i][1];
            a[i]={diag,area};
        }
        sort(a.begin(),a.end(),[](pair<int,int> a, pair<int,int> b){
            if(a.first != b.first){
                return a.first > b.first;
            }
            return a.second>b.second;
        });
        return a[0].second;
    }
};