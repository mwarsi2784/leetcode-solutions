class Solution {
int fun(vector<int>& nums, int i, int j, int target){
    int ans=-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(nums[mid]<=target){
            j=mid-1;
            ans=mid;
        }
        else{
            i=mid+1;
        }
    }
    return ans;
}

public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int ans=0;
        for(int i=0,j=0;i<n1 && j<n2;){
            if(i<=j && nums1[i]<=nums2[j]) ans=max(ans,j-i), j++;
            else if(i<=j) i++;
            else j++;
        }
        return ans;
    }
};