
class UnionFind{
public:
    vector<int> root;
    UnionFind(vector<int>& rains, int n){
        root.resize(n+1);
        root[n]=n;
        for(int i=n-1; i>=0; i--)
            root[i]=(rains[i])?root[i+1]:i;
    }
    int Find(int x){
        return (x==root[x])?x:root[x]=Find(root[x]);
    }
    void UnionNext(int x){
        root[x]=Find(x+1);
    }
};
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int n=rains.size();

        
        UnionFind G(rains, n); 
        unordered_map<int, int> rainDay;
        rainDay.reserve(n);
        vector<int> ans(n, 1);
        for(int i=0; i<n; i++){
            const int lake=rains[i];
            if (lake>0){
                ans[i]=-1;
                auto it=rainDay.find(lake);
                if (it!=rainDay.end()){
                    int prev=it->second;
                    int dry=G.Find(prev+1); 
                    if (dry>=i) return {};  
                    ans[dry]=lake;      
                    G.UnionNext(dry);   
                    it->second=i;                  
                }
                else rainDay[lake]=i;
            } 
        }
        return ans;
    }
};