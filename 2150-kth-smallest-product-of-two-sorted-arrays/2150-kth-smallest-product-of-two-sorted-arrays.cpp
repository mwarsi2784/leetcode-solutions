long long fun(vector<int>& nums1, vector<int>& nums2, long long target) {
    long long count = 0;
    for (int num1 : nums1) {
        if (num1 == 0) {
            if (target >= 0) count += nums2.size();
            continue;
        }
        int low = 0, high = nums2.size();
        while (low < high) {
            int mid = (low + high) / 2;
            long long prod = 1LL * num1 * nums2[mid];
            if (prod <= target) {
                if (num1 > 0) low = mid + 1;
                else high = mid;
            } else {
                if (num1 > 0) high = mid;
                else low = mid + 1;
            }
        }
        count += (num1 > 0) ? low : (nums2.size() - low);
    }
    return count;
}

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long result=0;
        long long l=-1e10;
        long long r=1e10;
        while(l<r){
            long long mid=l+(r-l)/2;
            if(fun(nums1,nums2,mid)>=k) r=mid;
            else{
                l=mid+1;
            }
        }
        return l;
    }
};