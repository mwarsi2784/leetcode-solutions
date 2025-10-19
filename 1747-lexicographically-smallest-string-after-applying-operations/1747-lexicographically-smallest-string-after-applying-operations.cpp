class Solution {
public:
string rotateString(string s, int b) {
    int n = s.size();
    if (n == 0) return s; // handle empty string
    b = b % n; // handle rotation greater than length

    // Right rotation: take last b chars to the front
    return s.substr(n - b) + s.substr(0, n - b);
}
    string findLexSmallestString(string s, int a, int b) {
        string ans(102,'9');
        stack<string> st;
        set<string> visited;
        visited.insert(s);
        st.push(s);
        while(!st.empty()){
            string curr=st.top();
            st.pop();
            if(curr<ans){
                ans=curr;
            }
            string add=curr;
            string rotate=curr;
            for(int i=1;i<add.size();i+=2){
                add[i]=(((a)+(curr[i]-'0'))%10)+'0';
            }
            rotate=rotateString(curr,b);
            if(visited.find(add)==visited.end()){
                visited.insert(add);
                st.push(add);
            }
            if(visited.find(rotate)==visited.end()){
                visited.insert(rotate);
                st.push(rotate);
            }
        }
        return ans;
    }
};