class Fancy {
public:
    long long add=0;
    long long mult=1;
    long long mod=1e9+7;
    vector<long long> seq;
    

    long long pow1(long long base, long long exponent) {
        long long result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent /= 2; 
        }
        return result;
    }

    Fancy() {
        seq.reserve(100000);
    }
    
    void append(int val) {
        long long temp = ((val-add+mod)%mod) * pow1(mult,mod-2)%mod;
        seq.push_back(temp);
    }
    
    void addAll(int inc) {
        add = (add+inc)%mod;
    }
    
    void multAll(int m) {
        mult =  (mult*m)%mod;
        add = (add*m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx>=seq.size()){
            return -1;
        }
        return (seq[idx]*mult+add)%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */