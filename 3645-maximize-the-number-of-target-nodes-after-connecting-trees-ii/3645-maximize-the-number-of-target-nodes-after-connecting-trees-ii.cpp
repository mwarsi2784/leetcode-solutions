vector<int> fun2(const vector<set<int>>& graph) {
    int n = graph.size();
    vector<int> level(n, -1);
    queue<int> q;
    q.push(0);
    level[0] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node]) {
            if (level[neighbor] == -1) {
                level[neighbor] = level[node] ^ 1; // Flip 0 <-> 1 for child
                q.push(neighbor);
            }
        }
    }
    int evenCount = 0, oddCount = 0;
    for (int l : level) {
        if (l % 2 == 0) ++evenCount;
        else ++oddCount;
    }
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = (level[i] % 2 == 0) ? evenCount : oddCount;
    }
    return result;
}


int fun(int i, const vector<set<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<pair<int, int>> q;
    int count = 0;
    q.push({i, 0});
    visited[i] = true;
    while (!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();
        if (dist % 2 == 0) {
            count++;
        }
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, dist + 1});
            }
        }
    }
    return count;
}



class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<set<int>> graph1(edges1.size()+1),graph2(edges2.size()+1);
        for(int i=0;i<edges1.size();i++){
            graph1[edges1[i][0]].insert(edges1[i][1]);
            graph1[edges1[i][1]].insert(edges1[i][0]);
        }
        for(int i=0;i<edges2.size();i++){
            graph2[edges2[i][0]].insert(edges2[i][1]);
            graph2[edges2[i][1]].insert(edges2[i][0]);
        }
        int mx=0;
        for(int i=0;i<=edges2.size();i++){
            int temp=fun(i,graph2);
            int temp2=edges2.size()+1-temp;
            temp=max(temp,temp2);
            mx=max(temp,mx);
        }
        vector<int> answers=fun2(graph1);
        for(int i=0;i<=edges1.size();i++){
            answers[i]=answers[i]+mx;
        }
        return answers;
    }
};