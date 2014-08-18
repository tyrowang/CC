/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *merge(ListNode *h1,ListNode *h2){
        if(h1==NULL) return h2;
        else if(h2==NULL) return h1;
        ListNode * ret; ListNode ** t=&ret;
        while(h1!=NULL&&h2!=NULL){
            if(h1->val<=h2->val){ *t=h1;h1=h1->next;t=&((*t)->next);}
            else { *t=h2;h2=h2->next;t=&((*t)->next);}
        }
        *t=(h1==NULL?h2:h1);
        return ret;
    }
    ListNode *mysort(ListNode *h,int n){
        if(n==0) return NULL;
        if(n==1) return h;
        int mid=n/2;
        ListNode *t=h;
        while(mid>1){
            t=t->next;mid--;
        }
        ListNode *h2=t->next;
        t->next=NULL;
        return merge(mysort(h,n/2),mysort(h2,n-n/2));
    }
    ListNode *sortList(ListNode *head) {
        ListNode *t=head;
        int n=0;
        while(t!=NULL){
            n++;
            t=t->next;
        }
        return mysort(head,n);
    }
};