class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> d1(edges.size(),10000000),d2(edges.size(),10000000);
        int curr=node1;
        int distance=0;
        set<int> v1,v2;
        do{
            v1.insert(curr);
            d1[curr]=distance;
            distance++;
            curr=edges[curr];
        }while(v1.find(curr)==v1.end() && curr!=-1);
        curr=node2;
        distance=0;
        do{
            v2.insert(curr);
            d2[curr]=distance;
            distance++;
            curr=edges[curr];
        }while(v2.find(curr)==v2.end() && curr!=-1);
        int ans=10000000;
        int ind=0;
        // for(int i=0;i<edges.size();i++){
        //     cout<<"d1="<<d1[i]<<" d2="<<d2[i]<<"\n";
        // }
        for(int i=0;i<edges.size();i++){
            int temp=max(d1[i],d2[i]);
            if(temp!=10000000 && temp<ans){
                ind=i;
                ans=temp;
            }
        }
        if(ans!=10000000){
            return ind;
        }
        return -1;
    }
};