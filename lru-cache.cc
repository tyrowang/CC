struct Node{
    int key;
    int value;
    Node(int k,int v){key=k;value=v;}
};

class LRUCache{
public:
// the list.remove is O(n), so the map is neccessary to store the point to the list.
    map<int,list<Node*>::iterator> cache_map;
    list<Node*> cache_list;
    int c;
    LRUCache(int capacity) {
        c=capacity;
    }
    int get(int key) {
        map<int,list<Node*>::iterator>::iterator it=cache_map.find(key);
        if(it==cache_map.end()){
            return -1;
        }else{
            cache_list.push_front(*(it->second));
            cache_list.erase(it->second);
            it->second=cache_list.begin();
            return (*(it->second))->value;
        } 
    }
    void set(int key, int value) {
        map<int,list<Node*>::iterator>::iterator it=cache_map.find(key);
        if(it!=cache_map.end()){
            cache_list.push_front(*(it->second));
            cache_list.erase(it->second);
            it->second=cache_list.begin();
            (*(it->second))->value=value;   
        }else{
            if(cache_map.size()>=c){
                cache_map.erase(cache_list.back()->key);
                delete cache_list.back();
                cache_list.pop_back();
            }
            Node* n=new Node(key, value);
            cache_list.push_front(n);
            cache_map[key]=cache_list.begin();
        }
    }
};