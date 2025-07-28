class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ans=0;
        int count=0;
        int subset=nums.size();
        subset=1<<subset;
        for(int i=0;i<nums.size();i++){
            ans=ans | nums[i];
        }
        for(int i=1;i<subset;i++){
            int temp=0;
            for(int j=0;j<nums.size();j++){
                if(i & (1<<j)){
                    temp=temp | nums[j];
                }
            }
            if(temp==ans){
                count++;
            }
        }
        return count;
    }
};