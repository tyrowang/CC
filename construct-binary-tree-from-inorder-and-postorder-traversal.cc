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
    TreeNode *helper(vector<int> &inorder,int i_l,int i_r, vector<int> &postorder,int cur){
        if(i_l==i_r){
            TreeNode* node=new TreeNode(postorder[cur]);
            return node;
        }
        if(i_l>i_r)
            return NULL;
        TreeNode * root=NULL;
        for(int i=i_r;i>=i_l;i--){
            if(inorder[i]==postorder[cur]){
                root=new TreeNode(postorder[cur]);
                root->right=helper(inorder,i+1,i_r,postorder,cur-1);
                root->left=helper(inorder,i_l,i-1,postorder,cur-i_r+i-1);
            }
        }
        return root;
    } 
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return helper(inorder,0,inorder.size()-1,postorder,postorder.size()-1);
    }
};