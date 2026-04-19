class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans=0;
        int i=0;
        int j=colors.size()-1;
        while(i<j){
            if(colors[i]!=colors[j]){
                ans=j-i;
                break;
            }
            j--;
        }
        i=0;
        j=colors.size()-1;
        while(i<j){
            if(colors[i]!=colors[j]){
                ans=max(ans,j-i);
                break;
            }
            i++;
        }
        return ans;
    }
};