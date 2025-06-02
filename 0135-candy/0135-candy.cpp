class Solution {
public:
    int candy(vector<int>& a) {
        vector<int> ans(a.size(),1);
        int n=a.size();
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1] && ans[i]<=ans[i-1]){
                ans[i]=ans[i-1]+1;
            }
        }
        int sum=ans[n-1];
        for(int i=n-2;i>=0;i--){
            if(a[i]>a[i+1] && ans[i]<=ans[i+1]){
                ans[i]=ans[i+1]+1;
            }
            sum=sum+ans[i];
        }
        return sum;
    }
};