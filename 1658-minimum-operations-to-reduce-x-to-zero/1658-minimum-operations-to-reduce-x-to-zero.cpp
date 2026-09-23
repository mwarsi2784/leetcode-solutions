class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(int i=0;i<nums.size();i++) total+=nums[i];
        int target=total-x;
        if(target<0) return -1;
        if(target==0) return nums.size();

        int mx=-1;
        int sum=0;
        int l=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];

            while(sum>target && l<=r){
                sum-=nums[l];
                l++;
            }

            if(sum==target){
                mx=max(mx,r-l+1);
            }
        }
        return mx != -1 ? nums.size() - mx : -1;
    }
};