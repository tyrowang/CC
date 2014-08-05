/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct OrderByVal{
bool operator()(const ListNode* a, const ListNode* b){return a->val > b->val;}
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // case []
        if(lists.empty()) return NULL;
        priority_queue<ListNode*,vector<ListNode*>,OrderByVal> mypq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
                mypq.push(lists[i]);
        }
        ListNode * ret=NULL;
        ListNode ** cur=&ret;
        while(!mypq.empty()){
            //ListNode *tmp=new ListNode(mypq.top().val);
            //*cur=tmp;
            *cur=mypq.top();
            cur=&((*cur)->next);
            if(mypq.top()->next!=NULL){
                ListNode * tmp=mypq.top()->next;
                mypq.pop();
                mypq.push(tmp);
            }else mypq.pop();
        }
        return ret;
    }
};