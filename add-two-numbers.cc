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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* d1=l1;
        ListNode* d2=l2;
        ListNode* ret=NULL;
        ListNode** p=&ret;
        int c=0;
        while(d1!=NULL&&d2!=NULL){
            int tmp=d1->val+d2->val+c;
            if(tmp>=10){
                c=1;
                tmp-=10;
            }else{
                c=0;
            }
            *p=new ListNode(tmp);
            d1=d1->next;
            d2=d2->next;
            p=&((*p)->next);
        }
        if(d1!=NULL){
            while(d1!=NULL){
                int tmp=d1->val+c;
                if(tmp>=10){
                    tmp-=10;
                    c=1;
                }
                else c=0;
                *p=new ListNode(tmp);
                p=&((*p)->next);
                d1=d1->next;
            }
        }else if(d2!=NULL){
            while(d2!=NULL){
                int tmp=d2->val+c;
                if(tmp>=10){
                    tmp-=10;
                    c=1;
                }else c=0;
                *p=new ListNode(tmp);
                p=&((*p)->next);
                d2=d2->next;
            }
        }
        if(c!=0){
            *p=new ListNode(c);
        }
        return ret;
    }
};