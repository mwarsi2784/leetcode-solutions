class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> f;
        set<int> s;
        for(int i=0;i<nums.size();++i){
            s.insert(nums[i]);
            f[nums[i]]++;
        }
        int ans=0;
        for(int i:s){
            if(f[i-1]!=0) ans=max(ans,f[i]+f[i-1]);
        }
        return ans;
    }
};