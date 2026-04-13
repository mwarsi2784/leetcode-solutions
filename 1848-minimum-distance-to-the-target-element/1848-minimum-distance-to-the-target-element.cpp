class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans1=1000000;
        int ans2=1000000;
        for(int i=start;i>=0;i--){
            if(nums[i]==target){
                ans1=min(ans1,abs(start-i));
                break;
            } 
        }
        for(int i=start;i<nums.size();i++){
            if(nums[i]==target){
                ans2=min(ans2,abs(start-i));
                break;
            } 
        }
        return min(ans1,ans2);
    }
};