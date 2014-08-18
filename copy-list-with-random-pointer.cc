/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(NULL==head)
            return NULL;
        RandomListNode* p=head;
        RandomListNode* r=head->next;
        RandomListNode** ret=&r;
        while(p){
            RandomListNode* q=p->next;
            p->next=new RandomListNode(p->label);
            p->next->next=q;
            p->next->random=p->random;
            p=q;
        }
        p=head;
        while(p){
           if(p->next->random!=NULL) p->next->random=p->next->random->next;
           p=p->next->next;
        }
        p=head;
        while(p){
            *ret=p->next;
            RandomListNode* q=(*ret)->next;
            p->next=q;
            p=q;
            ret=&((*ret)->next);
        }
        return r;
    }
};