class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod=1e9+7;
        int n=nums.size();
        int ans=0;
        int pow[n+1];
        pow[0]=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<=n;i++){
            pow[i]=(pow[i-1]*2)%mod;
        }
        int l=0;
        int r=n-1;
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                ans=(ans+pow[r-l])%mod;
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};