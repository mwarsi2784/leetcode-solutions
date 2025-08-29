class Solution {
public:
    long long flowerGame(int n, int m) {
        long odd1=0;
        long even1=0;
        long odd2=0;
        long even2=0;
        for(int i=1;i<=n;i++){
            if(i&1){
                odd1++;
            }else{
                even1++;
            }
        }
        for(int i=1;i<=m;i++){
            if(i&1){
                odd2++;
            }else{
                even2++;
            }
        }
        return odd2*even1+even2*odd1;
    }
};