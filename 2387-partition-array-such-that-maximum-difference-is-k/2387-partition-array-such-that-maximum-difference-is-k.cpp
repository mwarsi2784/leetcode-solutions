class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int partition =1;
        sort(nums.begin(),nums.end());
        int min=-1;
        for(int i=0;i<nums.size();i++){
            if(min==-1){
                min=nums[i];
            }
            if(nums[i]-min>k){
                min=nums[i];
                partition++;
            }
        }
        return partition;
    }
};