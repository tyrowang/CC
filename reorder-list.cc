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
    ListNode * rotate(ListNode *head){
        if(head==NULL||head->next==NULL) return head;
        ListNode *p=head,*q,*r=NULL;
//        ListNode *q;
//        ListNode *r=NULL;
        while(p!=NULL){
            q=p;
            p=p->next;
            q->next=r;
            r=q;
        }
        return q;
    }
    void reorderList(ListNode *head) {
        if(head==NULL||head->next==NULL) return; 
        ListNode * p=head;
        ListNode * q=head;
        int i;
        while(p){
            i=2;
            while(i&&p){p=p->next;i--;}
            if(p==NULL) break;
            q=q->next;
        }
        ListNode * h=q->next;
        q->next=NULL;
        h=rotate(h);
        p=head;
        while(h!=NULL){
            q=p->next;
            p->next=h;
            h=h->next;
            p->next->next=q;
            p=q;
        }
        
    }
};