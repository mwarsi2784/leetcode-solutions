class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int result = 0;
        vector<int> v;

        int prev = 0;
        for (int i = 0; i < n; i++) {
            v.push_back(prev + s[i] - '0');
            prev = v.back();
        }

        for (int i = 0; i < n; i++) {
            int tempResult = 0;
            for (int j = i; j < n; j++) {
                int countOfOne = v[j] - v[i] + s[i] - '0';
                int countOfZero = j - i + 1 - countOfOne;
                if (pow(countOfZero, 2) < countOfOne) {
                    tempResult++;
                    int jump = sqrt(countOfOne) - countOfZero;
                    if (j + jump >= n)
                        tempResult += n - j - 1;
                    else
                        tempResult += jump;
                    j += jump;
                } else if (pow(countOfZero, 2) > countOfOne) {
                    int jump = pow(countOfZero, 2) - countOfOne - 1;
                    j += jump;
                } else {
                    tempResult++;
                }
            }
            result += tempResult;
        }

        return result;
    }
};