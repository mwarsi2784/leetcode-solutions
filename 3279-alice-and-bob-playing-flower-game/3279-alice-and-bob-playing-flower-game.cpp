class Solution {
public:
    long long flowerGame(int n, int m) {
        long odd1=0;
        long even1=0;
        long odd2=0;
        long even2=0;
        even1=n/2;
        even2=m/2;
        odd1=((n%2)+n)/2;
        odd2=((m%2)+m)/2;
        return odd2*even1+even2*odd1;
    }
};