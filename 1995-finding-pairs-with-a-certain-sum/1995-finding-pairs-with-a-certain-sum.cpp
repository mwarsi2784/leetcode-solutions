class FindSumPairs {
public:
    vector<int> arr1,arr2;
    map<int,int> f,f2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1=nums1;
        arr2=nums2;
        for(int i=0;i<arr2.size();i++){
            f[arr2[i]]++;
        }
        for(int i=0;i<arr1.size();i++){
            f2[arr1[i]]++;
        }
        return;
    }
    
    void add(int index, int val) {
        int temp=arr2[index];
        f[temp]--;
        temp+=val;
        f[temp]++;
        arr2[index]=temp;
        return;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto i: f2){
            ans=ans+(i.second)*(f[tot-i.first]);
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */