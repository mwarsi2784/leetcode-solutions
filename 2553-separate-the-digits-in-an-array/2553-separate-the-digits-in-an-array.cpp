class Solution {
    int countLength(int n){
        if(n<10){
            return 1;
        }
        if(n<100){
            return 2;
        }
        if(n<1000){
            return 3;
        }
        if(n<10000){
            return 4;
        }
        if(n<100000){
            return 5;
        }
        return 6;
    }
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=0;
        for(int i=0;i<nums.size();i++){
            n+=countLength(nums[i]);
        }
        vector<int> ans(n,0);
        int j=n-1;
        for(int i=nums.size()-1;i>=0;i--){
            int num=nums[i];
            while(num>0){
                ans[j]=num%10;
                num=num/10;
                j--;
            }
        }
        return ans;
    }
};