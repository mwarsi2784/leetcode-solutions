/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int dfs(TreeNode* curr, string s){
        if(curr!=nullptr){
            s=s+((curr->val==1)?'1':'0');
            if(curr->left==nullptr){
                return dfs(curr->right,s);
            }
            if(curr->right==nullptr){
                return dfs(curr->left,s);
            }
            return dfs(curr->left,s) + dfs(curr->right,s);
        }
        else{
            cout<<s<<" ";
            return stoi(s, nullptr, 2);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,"");
    }
};