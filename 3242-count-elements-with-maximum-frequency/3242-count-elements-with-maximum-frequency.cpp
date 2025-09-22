class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> f;
        int mx=0;
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
            mx=max(f[nums[i]],mx);
        }
        int c=0;
        for(auto i:f){
            if(i.second==mx){
                c=c+i.second;
            }
        }
        return c;
    }
};