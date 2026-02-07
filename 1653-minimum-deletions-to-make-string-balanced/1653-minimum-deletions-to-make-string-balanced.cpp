class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> as(s.size(),0);
        for(int i=0;i<s.size();i++){
            if(i==0){
                as[i]=(s[i]=='a')?1:0;
            }
            else if(s[i]=='a'){
                as[i]=as[i-1]+1;
            }else{
                as[i]=as[i-1];
            }
        }
        if(as.back()==0){
            return 0;
        }
        if(as.back()==s.size()){
            return 0;
        }
        int ans=100000000;
        int totalA=as.back();
        for(int i=0;i<s.size();i++){
            int bCount;
            int aCount;
            if(i==0){
                bCount=0;
            }else{
                bCount=(i)-as[i-1];
            }
            if(i==s.size()-1){
                aCount=0;
            }else{
                aCount=as.back()-as[i];
            }
            ans=min(ans,aCount+bCount);
        }
        return ans;
    }
};