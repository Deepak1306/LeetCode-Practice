class LUPrefix {
public:
    vector<bool>v;
    int f=0;
    int m=0;
    LUPrefix(int n) {
        v.resize(n,false);
        
    }
    
    void upload(int video) {
        v[video-1]=true;
        m=max(m,video);
        
        while(f<m && v[f]==true){
            f++;
        }
        
    }
    
    int longest() {
        return f;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */