class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int right = nums.size() - 1;
        long long total_cost = 0;
        deque<pair<int, int>> q;
        long long res = 0;

        for (int left = (int)nums.size() - 1; left >= 0; left--) {
            int x = nums[left];
            int c = 1;

            while (!q.empty() && q.front().first < x) {
                auto [value, count] = q.front();
                q.pop_front();

                total_cost += 1LL * (x - value) * count;
                c += count;
            }

            q.push_front({x, c});

            while (total_cost > k) {
                auto [value, count] = q.back();
                q.pop_back();

                total_cost -= 1LL * value - nums[right];
                right--;

                if (count > 1) {
                    q.push_back({value, count - 1});
                }
            }

            res += right - left + 1;
        }

        return res;
    }
};