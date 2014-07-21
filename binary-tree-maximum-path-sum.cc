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
    void maxPath(TreeNode *root,int& with_root, int& wout_root){
        if(root==NULL){
            //case {-2,-1} not edit the variable local
            return;
        }
        else{
            int max_l=0,max_r=0,sub_l=0,sub_r=0;
            if(root->left==NULL&&root->right==NULL){
                with_root=root->val;
                wout_root=root->val;
            }else if(root->left!=NULL&&root->right==NULL){
                maxPath(root->left,sub_l,max_l);
                wout_root=max(max_l,root->val);
                if(sub_l<0){
                    with_root=root->val;
                }
                else{
                    with_root=sub_l+root->val;
                    wout_root=max(with_root,wout_root);
                }
            }else if(root->left==NULL&&root->right!=NULL){
                maxPath(root->right,sub_r,max_r);
                wout_root=max(max_r,root->val);
                if(sub_r<0){
                    with_root=root->val;
                }
                else{
                    with_root=sub_r+root->val;
                    wout_root=max(with_root,wout_root);
                }
            }
            else{
                maxPath(root->left,sub_l,max_l);
                maxPath(root->right,sub_r,max_r);
                if(max(sub_l,sub_r)<=0)
                    with_root=root->val;
                else{
                    with_root=max(sub_l,sub_r)+root->val;
                }
                wout_root=max(max_l,max_r);
                wout_root=max(with_root,wout_root);
                wout_root=max(wout_root,sub_l+sub_r+root->val);
            }
            //case: {-3}
            //case {1,2}
            //case:{2,-1,-2}
            //case:{-2,1}
            //case:{1,2,3}
            //case {-2,-1}
        }
    }
    int maxPathSum(TreeNode *root) {
        if(root==NULL)
            return 0;
        int wout_root,with_root;
        maxPath(root,wout_root,with_root);
        return max(wout_root,with_root);
            
    }
};
// star coder
class Solution {
public:
    int dfs (TreeNode *rt, int &ans) {
        ans = max(ans, rt->val);
        if (rt->left == NULL && rt->right == NULL)
            return rt->val;
        if (rt->left != NULL && rt->right == NULL) {
            int tmp = rt->val + dfs(rt->left, ans);
            ans = max(ans, tmp);
            return max(rt->val, tmp);
        }
        if (rt->left == NULL && rt->right != NULL) {
            int tmp = rt->val + dfs(rt->right, ans);
            ans = max(ans, tmp);
            return max(rt->val, tmp);
        }
        int tmp1 = dfs(rt->left, ans);
        int tmp2 = dfs(rt->right, ans);
        ans = max(ans, rt->val + max(tmp1, tmp2));
        ans = max(ans, rt->val + tmp1 + tmp2);
        return max(rt->val, rt->val + max(tmp1, tmp2));
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = -0x7ffffff;
        dfs(root, ans);
        return ans;
    }
};