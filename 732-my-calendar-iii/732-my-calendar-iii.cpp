class MyCalendarThree {
public:
//     static bool comp(pair<int,int>a, pair<int,int>b){
//         if(a.second==b.second){
//             return a.first<b.first;
//         }
        
//         return a.second<b.second;
//  
    
    map<int,int>mp;
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int ans=0;
        int k=0;
        
        for(auto it:mp){
            k+=it.second;
            ans=max(k,ans);
        }
        
        return ans;
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */