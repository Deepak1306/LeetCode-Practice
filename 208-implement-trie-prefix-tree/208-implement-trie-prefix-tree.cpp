
class Node{
    Node *arr[26];
    bool check=false;
    public:
    
    bool isPresent(char c){
        return arr[c-'a']!=NULL;
    }
    
    void put(char c,Node* node){
        arr[c-'a']=node;
    }
    
    Node* get(char c){
        return arr[c-'a'];
    }
    
    void setEnd(){
        check=true;
    }
    
    bool isEnd(){
        return check;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        
        for(int i=0;i<word.length();i++){
            if(!node->isPresent(word[i])){
                node->put(word[i],new Node());
                
            }
            
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        
        Node* node=root;
        
        for(int i=0;i<word.length();i++){
            if(!node->isPresent(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        
        if(node->isEnd()){
            return true;
        }
        
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        
        for(int i=0;i<prefix.length();i++){
            if(!node->isPresent(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */