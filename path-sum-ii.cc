/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ret;
        if(root==NULL)
            return ret;
        if(root->left==NULL&&root->right==NULL&&root->val==sum){
            vector<int> tmp(1,root->val);         //case {1} 1;careless initiation fault
            ret.push_back(tmp);
            return ret;
        }
        vector<vector<int> > lret;
        vector<vector<int> > rret;
        if(root->left!=NULL)
            lret=pathSum(root->left,sum-root->val);
        if(root->right!=NULL)
            rret=pathSum(root->right,sum-root->val);
        for(int i=0;i<lret.size();i++){
            vector<int> tmp=lret[i];
            tmp.insert(tmp.begin(),root->val);
            ret.push_back(tmp);
        }
        for(int i=0;i<rret.size();i++){
            vector<int> tmp=rret[i];
            tmp.insert(tmp.begin(),root->val);
            ret.push_back(tmp);
        }
        return ret;
    }
};