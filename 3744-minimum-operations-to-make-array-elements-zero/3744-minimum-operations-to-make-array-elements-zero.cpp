class Solution {
public:
    long long fun(int l, int r) {
        long long totalSteps = 0;
        int maxSteps = 0;
        
        for (int step = 0; step <= 16; step++) {
            long long  lowerBound = (1L << (2 * step));
            long long  upperBound = (1L << (2 * (step + 1))) - 1;
            
            if (lowerBound > r) break;
            
            long long rangeStart = max(1ll*l, lowerBound);
            long long rangeEnd = min(1ll*r, upperBound);
            
            if (rangeStart > rangeEnd) continue;
            
            long long count = rangeEnd - rangeStart + 1;
            totalSteps += count * (step + 1);
            maxSteps = max(maxSteps, step + 1);
        }
        
        return max(1ll*maxSteps, 1ll*(totalSteps + 1) / 2);
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;
        for(int i=0;i<queries.size();i++){
            ans=ans+fun(queries[i][0],queries[i][1]);
        }
        return ans;
    }
};