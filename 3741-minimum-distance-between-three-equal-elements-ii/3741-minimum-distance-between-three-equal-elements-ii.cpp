class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>> f;
        int ans=1000000000;
        int n=nums.size();
        for(int i=0;i<=n;i++){
            f[i]=vector<int>(3,1000000000);
        }
        for(int i=0;i<n;i++){
            f[nums[i]][0]=f[nums[i]][1];
            f[nums[i]][1]=f[nums[i]][2];
            f[nums[i]][2]=i;
            if(f[nums[i]][0]!=1000000000){
                ans=min(ans,abs(f[nums[i]][0]-f[nums[i]][1])+abs(f[nums[i]][1]-f[nums[i]][2])+abs(f[nums[i]][2]-f[nums[i]][0]));
            }
        }
        return (ans!=1000000000)?ans:-1;
    }
};