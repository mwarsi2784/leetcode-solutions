public class Solution {
    public bool IsPowerOfThree(int n) {
        int maxPower = (int)Math.Pow(3,19);
        if(n<=0){
            return false;
        }
        if(maxPower%n >=1){
            return false;
        }
        return true;
    }
}