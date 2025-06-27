    bool isKRepeatedSubsequence(const string& s, const string& t, int k) {
        int pos = 0, matched = 0;
        int n = s.size(), m = t.size();
        for (char ch : s) {
            if (ch == t[pos]) {
                pos++;
                if (pos == m) {
                    pos = 0;
                    matched++;
                    if (matched == k) {
                        return true;
                    }
                }
            }
        }

        return false;
    }


class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        map<char,int> freq;
        for (int i=0;i<s.size();i++) {
            freq[s[i]]++;
        }
        vector<char> candidate;
        for (char i = 'z'; i >= 'a'; i--) {
            if (freq[i] >= k) {
                candidate.push_back(i);
            }
        }
        queue<string> q;
        for (int i=0;i<candidate.size();i++) {
            q.push(string(1, candidate[i]));
        }

        string ans = "";
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            if (curr.size() > ans.size()) {
                ans = curr;
            }
            for (int i=0;i<candidate.size();i++) {
                string next = curr + candidate[i];
                if (isKRepeatedSubsequence(s, next, k)) {
                    q.push(next);
                }
            }
        }

        return ans;
    }
};