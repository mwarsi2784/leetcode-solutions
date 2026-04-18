class Solution {
public:
    int mirrorDistance(int n) {
        int mirr=0;
        int temp =n;
        while(temp>0){
            int rem=temp%10;
            mirr=mirr*10+rem;
            temp=temp/10;
            //cout<<mirr<<" ";
        }
        //cout<<mirr;
        return abs(n-mirr);
    }
};