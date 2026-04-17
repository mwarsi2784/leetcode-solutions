class Solution {
    int fun(int num){
        int ans=0;
        while(num>0){
            int rem=num%10;
            ans=ans*10+rem;
            num/=10;
        }
        return ans;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans=1000000000;
        map<int,int> f;
        for(int i=0;i<nums.size();i++){
            int mirr=fun(nums[i]);
            cout<<mirr<<" ";
            if(f.find(nums[i]) != f.end()){
                ans=min(ans,abs(i-f[nums[i]]));
            }
            f[mirr]=i;
        } 
        return (ans==1000000000)?-1:ans;
    }
};