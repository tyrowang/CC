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
    ListNode *deleteDuplicates(ListNode *head) {
        //case {1,1}
        if(head==NULL)
            return NULL;
        ListNode ** start=&head;
        ListNode ** end=&(head->next);
        int dup=0;
        while((*end)!=NULL){
            if((*start)->val!=(*end)->val){
                start=&((*start)->next);
                end=&((*end)->next);
            }else{
                dup=(*start)->val;
                while((*start)!=NULL&&(*start)->val==dup){
                    ListNode * tmp=*start;
                    *start=(*start)->next;
                    delete tmp;
                }
                if((*start)==NULL)
                    break;
                else end=&((*start)->next);
            } 
        }
        return head;
    }
};