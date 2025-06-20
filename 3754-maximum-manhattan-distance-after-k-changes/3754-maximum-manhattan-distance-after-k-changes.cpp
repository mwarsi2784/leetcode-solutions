int dist(int a, int b, int k) {
    return abs(a-b) + k * 2;
}

class Solution {
public:
    int maxDistance(string st, int k) {
        int ans = 0;
        int n = 0, s = 0, e = 0, w = 0;
        for (int i=0;i<st.size();++i) {
            if(st[i]=='N') n++;
            if(st[i]=='S') s++;
            if(st[i]=='E') e++;
            if(st[i]=='W') w++;
            int vertical =min({n, s, k});  
            int horizontal = min({e, w, k - vertical});  
            ans = max(ans,dist(n, s, vertical) + dist(e, w, horizontal));
        }
        return ans;
    }
};