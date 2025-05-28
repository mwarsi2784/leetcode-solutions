int fun(const vector<set<int>>& graph, int start, int k) {
    if (k < 0 || start < 0 || start >= graph.size()) return 0;
    unordered_set<int> visited;
    queue<pair<int, int>> q;
    visited.insert(start);
    q.push({start, 0});
    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (dist == k) continue;
        for (int neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                q.push({neighbor, dist + 1});
            }
        }
    }
    return visited.size();
}


class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<set<int>> graph1(edges1.size()+1),graph2(edges2.size()+1);
        for(int i=0;i<edges1.size();i++){
            graph1[edges1[i][0]].insert(edges1[i][1]);
            graph1[edges1[i][1]].insert(edges1[i][0]);
        }
        for(int i=0;i<edges2.size();i++){
            graph2[edges2[i][0]].insert(edges2[i][1]);
            graph2[edges2[i][1]].insert(edges2[i][0]);
        }
        vector<int> answers(edges1.size()+1);
        int mx=0;
        for(int i=0;i<=edges2.size();i++){
            mx=max(fun(graph2,i,k-1),mx);
        }
        for(int i=0;i<=edges1.size();i++){
            answers[i]=fun(graph1,i,k)+mx;
        }
        return answers;
    }
};