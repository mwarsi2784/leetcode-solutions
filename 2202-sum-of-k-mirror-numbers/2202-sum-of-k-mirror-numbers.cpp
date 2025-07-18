bool isPalindrome(const string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

string baseN(long long num,int base){
    string s="012345678";
    string ans="";
    while(num>0){
        ans=s[num%base]+ans;
        num=num/base;
    }
    return ans;
}

class Solution {
public:
    long long kMirror(int k, int n) {
        long long ans=0;
        int c=0;
        long long num=0;
        for (int length = 1; c<n; ++length) {
            int halfLength = (length + 1) / 2;
            int start = (length == 1) ? 1 : pow(10, halfLength - 1);
            int end = pow(10, halfLength);
            for (int i = start; i < end && c<n; ++i) {
                string half = to_string(i);
                string full = half;
                for (int j = length % 2 == 0 ? half.size() - 1 : half.size() - 2; j >= 0; --j) {
                    full += half[j];
                }
                long long temp=stoll(full);
                if(isPalindrome(baseN(temp,k))){
                    c++;
                    ans=temp+ans;
                }
            }
        }
        return ans;
    }
};