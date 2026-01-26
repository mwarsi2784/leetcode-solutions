class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minDiff=100000000;
        for(int i=0;i<arr.size()-1;i++){
            minDiff=min(minDiff,arr[i+1]-arr[i]);
        }
        vector<vector<int>> ans;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==minDiff){
                vector<int> temp={arr[i],arr[i+1]};
                ans.push_back(temp);
            }
        }
        return ans;
    }
};