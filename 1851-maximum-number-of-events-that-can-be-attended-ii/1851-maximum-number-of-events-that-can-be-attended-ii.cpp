class Solution {
public:
    int findNextEvent(int i, const vector<vector<int>>& events) {
        int target = events[i][1];
        auto it = upper_bound(
            events.begin(), events.end(),
            vector<int>{target, INT_MAX, INT_MAX}
        );
        return it - events.begin(); 
    }

    int solve(int i, int k, vector<vector<int>>& dp, const vector<vector<int>>& events) {
        if (i >= events.size() || k == 0)
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];

        int skip = solve(i + 1, k, dp, events);

        int nextIndex = findNextEvent(i, events);
        int take = events[i][2] + solve(nextIndex, k - 1, dp, events);

        return dp[i][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); 
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(0, k, dp, events);
    }
};