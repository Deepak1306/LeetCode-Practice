class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int k=nums2.size();
        
        stack<int>s;
        vector<int>ans;
        
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums1[i]]=1;
        }
        
        for(int i=k-1;i>=0;i--){ 
            if(m.find(nums2[i])==m.end()){
                s.push(nums2[i]);
                continue;
            }
            
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            
            if(s.empty()){
                m[nums2[i]]=-1;
            }else{
                m[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
            
        }
        
        for(int i=0;i<n;i++){
            ans.push_back(m[nums1[i]]);
        }
        
        return ans;
    }
};