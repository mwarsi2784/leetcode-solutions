class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans(n/3,vector<int>(3));
        int len=3;
        for(int i=0;i+len<=n;i+=3){
            vector<int> temp(3);
            for(int j=0;j<3;j++){
                temp[j]=nums[j+i];
            }
            if(temp[2]-temp[0]>k){
                vector<vector<int>> a;
                return a;
            }
            ans[i/3]=temp;
        }
        return ans;
    }
};