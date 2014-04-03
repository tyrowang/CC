/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)
            return;
        TreeLinkNode * cnxt=NULL;
        TreeLinkNode * nxtlevel=NULL;
        TreeLinkNode * q=root;
        while(q){
            if(q->left){
                if(cnxt)
                    cnxt->next=q->left;
                cnxt=q->left;
                if(nxtlevel==NULL)
                    nxtlevel=cnxt;
            }
            if(q->right){
                if(cnxt)
                    cnxt->next=q->right;
                cnxt=q->right;
                if(nxtlevel==NULL)
                    nxtlevel=cnxt;
            }
           q=q->next;
        }
        connect(nxtlevel);
    }
};