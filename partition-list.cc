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
    ListNode *partition(ListNode *head, int x) {
        if(head==NULL)
            return NULL;
        ListNode **cur=&head;
        ListNode **sig=NULL;
        while((*cur)!=NULL&&(*cur)->val<x) cur=&(*cur)->next;
        sig=&(*cur);//used without being initialized *sig=*cur
        //*sig=(*sig)->next, cur will change with sig,because they are pointing the same place
        while((*sig)!=NULL){
            while((*sig)!=NULL&&(*sig)->val>=x) sig=&(*sig)->next;
            if((*sig)!=NULL){
                ListNode * tmp1=*cur;
                *cur=*sig;
                *sig=(*sig)->next;
                (*cur)->next=tmp1;
                cur=&(*cur)->next;
            }
        }
        return head;
    }
};