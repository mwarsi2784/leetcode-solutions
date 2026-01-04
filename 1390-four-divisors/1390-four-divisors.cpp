class Solution {
    long long fun(int n){
        long long count =0;
        long long sum=0;
        for(int i=1;i*i<=n;i++){
            if(i*i==n){
                return 0;
            }
            if(n%i==0){
                count+=2;
                sum+=i;
                sum=sum+(n/i);
            }
        }
        if(count ==4){
            return sum;
        }
        return 0*1ll;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans+fun(nums[i]);
        }
        return ans;
    }
};