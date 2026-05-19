class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        while(i<n && j<m && nums1[i]!=nums2[j]){
            if(nums1[i]<nums2[j]){
                i++;
            }else{
                j++;
            }
        }
        if(i<n && j<m){
            return nums1[i];
        }else{
            return -1;
        }
    }
};