class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int mx=0;
        for(int i=0;i<nums.size();i++){
            mx=max(nums[i],mx);
        }
        for(int i=0;i<nums.size();i++){
            int curr=0;
            while(i<nums.size() && nums[i]==mx){
                curr++;
                i++;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};