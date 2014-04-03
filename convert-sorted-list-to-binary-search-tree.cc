/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode * arrayToBST(vector<int> &array, int left, int right){//&array otherwise a lot of memory waste
        if(left==right){
             TreeNode* T=new TreeNode(array[left]);
             return T;
        }
        int mid=(left+right)/2;
        TreeNode* T=new TreeNode(array[mid]);
        if(mid-1>=left)
            T->left=arrayToBST(array,left,mid-1);
        if(mid+1<=right)
            T->right=arrayToBST(array,mid+1,right);
        return T;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        TreeNode* root=NULL;
        if(head==NULL)
            return root;
        vector<int> tmp;
        while(head!=NULL){
            tmp.push_back(head->val);
            ListNode* p=head;
            head=head->next;
            delete p;
        }

        int left=0;
        int right=tmp.size()-1;
        root=arrayToBST(tmp,left,right);
        return root;
        
    }
};