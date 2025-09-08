class Solution {
bool fun(int number) {
    // Handle the case of zero itself
    if (number == 0) {
        return false; // Zero contains the digit zero
    }

    // Take the absolute value to handle negative numbers
    int tempNumber = std::abs(number);

    while (tempNumber > 0) {
        int digit = tempNumber % 10; // Get the last digit
        if (digit == 0) {
            return false; // Found a zero
        }
        tempNumber /= 10; // Remove the last digit
    }
    return true; // No zero found
}
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans(2);
        for(int i=1;i<=n;i++){
            int t1=i;
            int t2=n-i;
            ans[0]=t1;
            ans[1]=t2;
            if(fun(t1)&&fun(t2)){
                return ans;
            }
        }
        return ans;
    }
};