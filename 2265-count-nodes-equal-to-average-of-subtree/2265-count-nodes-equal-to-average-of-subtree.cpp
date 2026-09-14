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
    pair<int,int> fun(TreeNode* root, int *n){
        pair<int,int> left={0,0};
        pair<int,int> right={0,0};
        if(root->left!=NULL){
            left=fun(root->left,n);
        }
        if(root->right!=NULL){
            right=fun(root->right,n);
        }
        int total = root->val + left.first + right.first;
        int avg = total/(left.second+right.second+1);
        if(avg==root->val){
            (*n)++;
        }
        
        pair<int,int> curr={total,left.second+right.second+1};
        return curr;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int n=0;
        pair<int,int> temp = fun(root,&n);
        return n;
    }
};