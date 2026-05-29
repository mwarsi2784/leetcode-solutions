class Solution {
    int fun(int n){
        int ans=0;
        do{
            ans=ans+n%10;
            n=n/10;
        }while(n>0);
        return ans;
    }
public:
    int minElement(vector<int>& nums) {
        int ans = 99999999;
        for(int i=0;i<nums.size();++i){
            ans=min(ans,fun(nums[i]));
        }
        return ans;
    }
};