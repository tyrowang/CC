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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        queue<TreeNode*> q;
        vector<vector<int> > ret;
        vector<int> l;
        int level=0;
        TreeNode* flag= NULL;
        //new TreeNode(-1);
        if(root){
            q.push(root);
            q.push(flag);
        }
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            if(t!=flag){
                l.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            else if(!l.empty()){
                if(level%2!=0)
                   reverse(l.begin(),l.end());
                vector<int> tmp_l(l);
                ret.push_back(tmp_l);
                l.clear();
                level++;
                q.push(flag);
            }
        }
        return ret;
    }
};