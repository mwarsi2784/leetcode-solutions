class Solution {
public:
    void fun(vector<vector<long long>>& dist){
        for(int k=0;k<26;k++){
            for(int j=0;j<26;j++){
                for(int i=0;i<26;i++){
                    if(dist[i][k]!=-1 && dist[k][j]!=-1){
                        if(dist[i][j]!=-1) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                        if(dist[i][j]==-1) dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(26,vector<long long>(26,-1*1ll));
        for(int i=0;i<original.size();i++){
            int n=original[i]-97;
            int m=changed[i]-97;
            if(n==m){
                dist[n][m]=0;
            }
            else if(dist[n][m]==-1){
                dist[n][m]=cost[i];
            }
            else {
                dist[n][m]=min(dist[n][m],1ll*cost[i]);
            }
        }
        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }
        fun(dist);
        long long ans=0;
        for(int i=0;i<source.size();++i){
            int n=source[i]-97;
            int m=target[i]-97;
            if(dist[n][m]==-1){
                return -1;
            }
            ans=ans+dist[n][m];
        }
        return ans;
    }
};