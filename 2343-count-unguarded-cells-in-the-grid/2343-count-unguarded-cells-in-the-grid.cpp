class Solution {
public:
    int countUnguarded(int h, int w, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        std::vector<bool> obstacle(w*h), visited(w*h);
        for (auto& g: guards) obstacle[g[0]*w + g[1]] = 1;
        for (auto& wall: walls) obstacle[wall[0]*w + wall[1]] = 1;
        auto visit = [&](unsigned x, unsigned y, int dx, int dy) {
            int i = w*y + x, o = dx ? dx : w * dy;
            x += dx, y += dy, i += o;
            while (x < w && y < h && !obstacle[i]) {
                visited[i] = 1;
                x += dx, y += dy, i += o;
            }
        };
        for (auto& g: guards) {
            int y = g[0], x = g[1];
            visit(x, y, 1, 0);
            visit(x, y, 0, 1);
            visit(x, y, -1, 0);
            visit(x, y, 0, -1);
        }

        return w*h - walls.size() - guards.size() - ranges::count(visited, 1);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();