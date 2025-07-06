class FindSumPairs {
public:
    vector<int> arr1,arr2;
    map<int,int> f;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1=nums1;
        arr2=nums2;
        for(int i=0;i<arr2.size();i++){
            f[arr2[i]]++;
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
        for(int i=0;i<arr1.size();i++){
            ans=ans+f[tot-arr1[i]];
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