class Solution {
    int stringToInt(string &s){
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            ans= ans + ((s[i]&1)*(1<<(n-i-1)));
        }
        cout<<ans<<" ";
        return ans;
    } 
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> freq(17,0);
        for(int i=0;i<nums.size();i++){
            int temp=stringToInt(nums[i]);
            if(temp<17) freq[temp]++;
        }
        int n=nums.size();
        for(int i=0;i<17;i++){
            if(freq[i]==0){
                string s="";
                int num=i;
                for(int j=0;j<n;j++){
                    if(num%2==0){
                        s=s+'0';
                    }else{
                        s=s+'1';
                    }
                    num=num/2;
                }
                reverse(s.begin(),s.end());
                return s;
            }
        }
        return "";
    }
};