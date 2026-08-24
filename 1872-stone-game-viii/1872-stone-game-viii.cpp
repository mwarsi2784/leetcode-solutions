class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        
        int max_diff = stones[n - 1];
        
        for (int i = n - 2; i >= 1; --i) {
            max_diff = std::max(max_diff, stones[i] - max_diff);
        }
        
        return max_diff;
    }
};