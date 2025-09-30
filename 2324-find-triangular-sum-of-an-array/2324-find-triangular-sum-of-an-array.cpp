class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> prev=nums;
        for(int i=0;i<nums.size();i++){
            vector<int> temp(prev.size()-1);
            for(int i=0;i<prev.size()-1;i++){
                temp[i]=(prev[i]+prev[i+1])%10;
            }
            prev=temp;
        }
        return prev[0];
    }
};