class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans=0;
        ans=abs(nums[0]-nums[nums.size()-1]);
        for(int i=1;i<nums.size();i++){
            ans=max(ans,abs(nums[i]-nums[i-1]));
        }
        return ans;
    }
};