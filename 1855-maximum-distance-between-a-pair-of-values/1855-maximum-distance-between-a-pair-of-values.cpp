class Solution {
int fun(vector<int>& nums, int i, int j, int target) {
    int ans = -1; 
    while (i <= j) {
        int mid = i + (j - i) / 2;
        if (nums[mid] <= target) {
            ans = mid; 
            j = mid - 1;   
        } else {
            i = mid + 1;
        }
    }
    return ans;
}
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(int i=0;i<nums2.size();i++){
            int n=nums1.size()-1;
            int ind=fun(nums1,0,min(i,n),nums2[i]);
            if(ind!=-1) ans=max(ans,i-ind);
        }
        return ans;
    }
};