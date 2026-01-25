class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(k==1){
            return 0;
        }
        int l=0;
        int r=0;
        int mx=0;
        int mn=1000000000;
        while(r<k){
            mx=max(mx,nums[r]);
            mn=min(mn,nums[r]);
            r++;
        }
        r--;
        int ans=1000000000;
        while(r<nums.size()){
            ans=min(ans,mx-mn);
            r++;
            l++;
            mn=nums[l];
            mx=nums[r];
        }
        return ans;
    }
};