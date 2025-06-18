class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        int len=3;
        for(int i=0;i+len<=nums.size();i+=len){
            cout<<i;
            vector<int> temp;
            for(int j=0;j<len;j++){
                temp.push_back(nums[j+i]);
            }
            if(temp[temp.size()-1]-temp[0]>k){
                vector<vector<int>> a;
                return a;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};