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
//case:{3,1,2}
//case:{1,2,3}
    void inorder(TreeNode * root, vector<TreeNode*> &swap){
         if(root==NULL) return;
         if(root->left!=NULL) inorder(root->left,swap);
         if(swap.size()<1) swap.push_back(root);
         else if(swap.size()==1&&root->val<swap.back()->val) swap.push_back(root);
         else if(swap.size()==1&&root->val>swap.back()->val) swap.back()=root;
         else if(swap.size()==2&&root->val<swap.back()->val) swap.back()=root;
         if(root->right!=NULL) inorder(root->right,swap);
         }
    void recoverTree(TreeNode *root) {
        if(root==NULL)
            return;
        vector<TreeNode*> swap;
        inorder(root,swap);
        if(swap.size()>1){
            int tmp=swap[0]->val;
            swap[0]->val=swap.back()->val;
            swap.back()->val=tmp;
        }
    }
};