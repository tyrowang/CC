class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        //case {1,1}
        if(NULL==head)
            return NULL;
        ListNode *cur=head,*sig=cur->next;
        while(sig!=NULL){
            cur=head;
            while(cur->val<=sig->val&&cur!=sig)
                cur=cur->next;
            if(cur!=sig){
                int pre=sig->val;
                while(cur!=sig->next){
                    int t=pre;
                    pre=cur->val;
                    cur->val=t;
                    cur=cur->next;
                }
            }
            sig=sig->next;
        }
        return head;
    }
};