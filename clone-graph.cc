/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *helper(map<int,UndirectedGraphNode*>&mymap,UndirectedGraphNode *node){
        if(node==NULL)
            return NULL;
        UndirectedGraphNode * ret=new UndirectedGraphNode(node->label);
        mymap[node->label]=ret;
        ret->neighbors=node->neighbors;
        map<int,UndirectedGraphNode*>::iterator it;
        for(int i=0;i<node->neighbors.size();i++){
            it=mymap.find(node->neighbors[i]->label);
            if(it==mymap.end())
                ret->neighbors[i]=helper(mymap,node->neighbors[i]);
            else
                ret->neighbors[i]=it->second;
        }
        return ret;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int,UndirectedGraphNode*> mymap;
        UndirectedGraphNode *ret=helper(mymap,node);
        return ret;
    }
};