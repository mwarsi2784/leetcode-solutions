class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int shift=0;
        vector<long long> length;
        long long len=1;
        for(int i=0;i<operations.size();i++){
            len<<=1;
            length.push_back(len);
            if(len>=k){
                break;
            }
        }
        for(int i=length.size()-1;i>=0;i--){
            long long half=length[i]/2;
            int op=operations[i];
            if(k>half){
                k-=half;
                if(op==1){
                    shift++;
                }
            }
        }
        char ans='a';
        for(int i=0;i<shift;i++){
            if(ans=='z'){
                ans='a';
            }else{
                ans=ans+1;
            }
        }
        return ans;
    }
};