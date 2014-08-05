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
     ListNode* rotate(ListNode*head){
        if(head==NULL)
            return NULL;
        ListNode * p;
        ListNode * q=head;
        ListNode * r=NULL;
        while(q!=NULL){ // bug when rotate q and *next point the same address at the same time
            p=q->next;
            q->next=r;
            r=q;
            q=p;
        }
        return r;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        //case {1} 1
        if(head==NULL) return NULL;
        ListNode ** start=&head;
        ListNode * end=head;
        int c0=0,c1=k-1;
        while(end!=NULL){
            end=end->next;
            c0++;
        }
        if(c0<k||k==1) return head;
        end=head;
        //if(c0==k) rotate(*head,*end);
        while(c0-k>=0){
            while(c1>0){end=end->next;c1--;}
            ListNode *tmp=end->next;
            end->next=NULL;
             ListNode *tmp2=*start;
            *start=rotate(tmp2);
            while(*start!=NULL) start=&(*start)->next;
            c0-=k;
            c1=k-1;
            *start=tmp;
            end=tmp;
        }
        return head;
    }
};