class Solution {

    bool isValid(vector<vector<int>>& points,int i, int j){
        if(points[i][1]>points[j][1] && points[i][0]>points[j][0]){
            return false;
        }
        if(points[j][1]>points[i][1] && points[j][0]>points[i][0]){
            return false;
        }
        int mxX=max(points[i][0],points[j][0]);
        int mnX=min(points[i][0],points[j][0]);
        int mxY=max(points[i][1],points[j][1]);
        int mnY=min(points[i][1],points[j][1]);
        for(int k=0;k<points.size();k++){
            if(k==i || k==j){
                continue;
            }
            int x=points[k][0];
            int y=points[k][1];
            if(x>=mnX && x<=mxX && y>=mnY && y<=mxY){
                return false;
            }
        }
        return true;
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isValid(points,i,j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};