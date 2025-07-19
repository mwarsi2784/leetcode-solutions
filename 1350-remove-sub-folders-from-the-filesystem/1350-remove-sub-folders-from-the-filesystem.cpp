bool fun(string parent, string child){
    int i=0;
    if(child.size()<=parent.size()){
        return true;
    }
    while(i<parent.size()){
        if(parent[i]!=child[i]){
            return true;
        }
        i++;
    }
    if(i<child.size()){
        if(child[i]!='/'){
            return true;
        }
    }
    return false;
}



class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();++i){
            string prev=ans.back();
            if(fun(prev,folder[i])){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};