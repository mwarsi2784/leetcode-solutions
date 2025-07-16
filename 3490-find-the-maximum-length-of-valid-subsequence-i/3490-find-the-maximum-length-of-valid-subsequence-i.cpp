class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd=0;
        int even=0;
        int oe=0;
        int eo=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                even++;
                if(eo%2==0){
                    eo++;
                }
                if(oe%2==1){
                    oe++;
                }
            }
            else{
                odd++;
                if(oe%2==0){
                    oe++;
                }
                if(eo%2==1){
                    eo++;
                }
            }
        }
        return max(max(even,odd),max(oe,eo));
    }
};