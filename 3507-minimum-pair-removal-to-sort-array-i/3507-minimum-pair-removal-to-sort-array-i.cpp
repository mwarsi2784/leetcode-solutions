class Solution {
public:
    bool fun(vector<int> &a){
        for(int i=0;i<a.size()-1;i++){
            if(a[i]>a[i+1]){
                return true;
            }
        }
        return false;
    }
    int minPairSum(vector<int> &a){
        int ans=200000;
        for(int i=0;i<a.size()-1;i++){
            ans=min(ans,a[i]+a[i+1]);
        }
        return ans;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ans=0;
        while(fun(nums)){
            vector<int> arr;
            int minPair=minPairSum(nums);
            int i=0;
            ans++;
            bool isOp=false;
            for(int i=0;i<nums.size();i++){
                if((!isOp) && nums[i]+nums[i+1]==minPair){
                    arr.push_back(nums[i]+nums[i+1]);
                    i++;
                    isOp=true;
                }
                else{
                    arr.push_back(nums[i]);
                }
            }
            nums=arr;
        }
        return ans;
    }
};