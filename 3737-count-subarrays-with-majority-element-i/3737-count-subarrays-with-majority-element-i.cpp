class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int> targetcount(nums.size()+1,0);
        if(nums[0]==target){
            targetcount[0]++;
        }
        for(int i=1;i<nums.size();i++){
            targetcount[i]=targetcount[i-1]+(nums[i]==target?1:0);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++) for(int j=i;j<nums.size();j++){
            int total=j-i+1;
            int tc=0;
            if(i==j && nums[i]==target) tc=1;
            else if(i==0) tc=targetcount[j];
            else tc=targetcount[j]-targetcount[i-1];
            int rem=total-tc;
            if(tc>rem) ans++;
        }
        return ans;
    }
};