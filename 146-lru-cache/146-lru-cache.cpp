class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator>m;
    int size;
    list<pair<int,int>>l;
    
    LRUCache(int capacity) {
      size=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        
        l.splice(l.begin(),l,m[key]);
        
        return m[key]->second;
        
        
    }
    
    void put(int key, int value) {
        
        if(m.find(key)!=m.end()){
            l.splice(l.begin(),l,m[key]);
            m[key]->second=value;
            return ;
        }
        
        if(l.size()==size){
            int k=l.back().first;
            l.pop_back();
            
            m.erase(k);
        }
        
        l.push_front({key,value});
        m[key]=l.begin();
        return ;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */