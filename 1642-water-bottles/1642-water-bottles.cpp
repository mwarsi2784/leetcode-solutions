class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        int r=0;
        while(numBottles>0){
            ans+=numBottles;
            r+=numBottles;
            numBottles=r/numExchange;
            r=r%numExchange;
        }
        return ans;
    }
};