class Solution {
    int fun(int x1,int y1, int x2,int y2, int x3,int y3){
        return abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int ans=0;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                for(int k=j+1;k<points.size();k++){
                    ans=max(ans,fun(points[i][0],points[i][1],points[j][0],points[j][1],points[k][0],points[k][1]));
                }
            }
        }
        return (double)(ans/2.0);
    }
};