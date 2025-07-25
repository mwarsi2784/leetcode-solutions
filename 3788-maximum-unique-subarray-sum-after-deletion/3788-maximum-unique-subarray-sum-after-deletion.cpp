class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum=0;
        vector<int> freq(101,0);
        int mn=-1000;
        for(int i=0;i<nums.size();i++){
            mn=max(mn,nums[i]);
            if(nums[i]>=1 && freq[nums[i]]==0){
                freq[nums[i]]++;
                sum+=nums[i];
            }
        }
        if(mn<=0){
            return mn;
        }
        return sum;
    }
};