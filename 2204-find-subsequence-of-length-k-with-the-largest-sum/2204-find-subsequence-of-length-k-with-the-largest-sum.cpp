class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> a(nums.size()),b(k);
        for(int i=0;i<nums.size();i++){
            a[i]={nums[i],i};
        } 
        sort(a.begin(),a.end());
        int n=nums.size();
        for(int i=0;i<k;i++){
            b[i]={a[n-i-1].second,a[n-i-1].first};
        }
        sort(b.begin(),b.end());
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            ans[i]=b[i].second;
        }
        return ans;
    }
};