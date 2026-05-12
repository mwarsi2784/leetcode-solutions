class Solution {
    static bool fun(vector<int> a, vector<int> b){
        return (a[1] - a[0]) > (b[1] - b[0]);
    }
    bool fun2(vector<vector<int>>& tasks, int x){
        for(int i=0;i<tasks.size();i++){
            if(x<tasks[i][1]){
                return false;
            }
            x=x-tasks[i][0];
        }
        if(x>=0){
            return true;
        }
        return false;
    }
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),fun);
        int l=1;
        int r=1000000000;
        int mid;
        int ans;
        while(l<=r){
            mid=l+(r-l)/2;
            if(fun2(tasks,mid)){
                r=mid-1;
                ans=mid;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};