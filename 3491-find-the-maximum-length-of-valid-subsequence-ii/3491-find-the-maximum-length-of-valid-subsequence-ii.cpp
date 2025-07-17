class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=2;
        if(k==1){
            return n;
        }
        vector<int> mod(n);
        for(int i=0;i<n;i++){
            mod[i]=nums[i]%k;
        }
        for(int j=0;j<k;j++){
            vector<int> memo(k);
            for(int i=0;i<n;i++){
                int m=mod[i];
                int pos=(j-m+k)%k;
                memo[m]=memo[pos]+1;
                ans=max(ans,memo[m]);
            }
        }
        return ans;
    }
};