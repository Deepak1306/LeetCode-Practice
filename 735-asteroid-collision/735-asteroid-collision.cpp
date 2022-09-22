class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int>ans;
        stack<int>st;
        
        int n=arr.size();
        bool check=false;
        
        for(int i=0;i<n;i++){
            int x=arr[i];
                
                while(!st.empty() && st.top()>0 && x<0){
                    if(abs(x)<st.top()){
                        check=true;
                        break;
                    }else if(!st.empty() && abs(x)==st.top()){
                        st.pop();
                        check=true;
                        break;
                    }else{
                        st.pop();
                    }  
                }
            
            if(!check){
                st.push(x);
            }
            check=false;
             
            
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};