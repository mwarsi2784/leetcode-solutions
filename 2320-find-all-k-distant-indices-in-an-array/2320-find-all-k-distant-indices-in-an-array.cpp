class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        set<int> a;
        vector<int> j;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                a.insert(i);
                int c=1;
                while(c<=k && c+i<n){
                    a.insert(c+i);
                    c++;
                }
                c=1;
                while(c<=k && i-c>=0){
                    a.insert(i-c);
                    c++;
                }
            }
        }
        for(auto i:a){
            ans.push_back(i);
        }
        return ans;

    }
};