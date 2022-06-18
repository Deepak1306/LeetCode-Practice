// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
          int size;
          list<pair<int,int>>li;
          unordered_map<int,list<pair<int,int>>::iterator>m;
    public:
    //Constructor for initializing the cache capacity with the given value.
    
    LRUCache(int cap)
    {
        // code here
        size=cap;
        
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(m.find(key)==m.end()){
            return -1;
        }
        
        li.splice(li.begin(),li,m[key]);
        return m[key]->second;
        
        
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here
        if(m.find(key)!=m.end()){
            li.splice(li.begin(),li,m[key]);
            m[key]->second=value;
            return ;
        }
        
        if(li.size()==size){
            int k=li.back().first;
            li.pop_back();
            m.erase(k);
            
        }
        li.push_front({key,value});
        m[key]=li.begin();
        return ;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends