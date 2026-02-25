class Solution {
public:
    static bool fun(int a, int b){
            if(__builtin_popcount(a) != __builtin_popcount(b)  ){
                return __builtin_popcount(a)<__builtin_popcount(b);
            }
            else{
                return a<b;
            }
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),fun);
        return arr;
    }
};