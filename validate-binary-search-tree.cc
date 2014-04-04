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
    //not so simple 10,5,15,#,#,6,20
  
    void visitBST(TreeNode *root,vector<int> &num){
        if(root!=NULL){
            visitBST(root->left,num);
            num.push_back(root->val);
            visitBST(root->right,num);
        }
            
    }
    bool isValidBST(TreeNode *root) {
        vector<int> num;
        visitBST(root,num);
        for(int i=1;i<num.size();i++){
           if(num[i]<=num[i-1]){
               return false;
           }
        }
        return true;
    }
};


//bool isValidBST(TreeNode *root) {
//        if (root==NULL)
//            return true;
//        else {
//            bool l=true,r=true;
//            if(root->left!=NULL&&root->left->val>=root->val)
//                l=false;
//            if(root->right!=NULL&&root->right->val<=root->val)
//                r=false;
//            if(r&&l){
//                if(isValidBST(root->left)&&isValidBST(root->right))
//                    return true;
//            }
//            else
//                return false;
//        }
//}