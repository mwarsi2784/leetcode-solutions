class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "NaN"; // undefined
        if (numerator == 0) return "0";     // zero numerator case

        // Step 1: Handle sign safely before abs
        bool negative = ((numerator < 0) ^ (denominator < 0));

        // Step 2: Convert safely to long long
        long long num = llabs((long long) numerator);
        long long den = llabs((long long) denominator);

        // Step 3: Reduce fraction
        long long g = std::gcd(num, den);   // gcd returns long long in C++17
        num /= g;
        den /= g;

        // Step 4: Integer part
        long long q = num / den;
        long long r = num % den;
        string ans = to_string(q);

        if (r == 0) return negative ? "-" + ans : ans; // no fractional part

        ans += '.';

        // Step 5: Check if decimal is finite
        long long factor = den;
        while (factor % 2 == 0) factor /= 2;
        while (factor % 5 == 0) factor /= 5;
        bool finiteDecimal = (factor == 1);

        // Step 6: Fractional part
        string frac;
        unordered_map<long long, int> mp;
        for (int i = 0; r != 0; i++) {
            if (!finiteDecimal) {
                if (mp.count(r)) {
                    frac.insert(mp[r], "(");
                    frac += ')';
                    break;
                }
                mp[r] = i;
            }
            r *= 10;
            frac.push_back('0' + r / den);
            r %= den;
        }

        // Step 7: Prepend sign if needed
        return negative ? "-" + ans + frac : ans + frac;
    }
};
