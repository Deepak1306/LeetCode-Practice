class Solution {
public:
    vector<int> mergeSort(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size();
        int m=nums2.size();
        
        vector<int>ans;
        int i=0;
        int j=0;
        
        while(i<n && j<m){
            if(nums2[j]<nums1[i]){
                ans.push_back(nums2[j]);
                j++;
            }else{
                ans.push_back(nums1[i]);
                i++;
            }
        }
        
        while(i<n){
            ans.push_back(nums1[i]);
            i++;
        }
        
        while(j<m){
            ans.push_back(nums2[j]);
            j++;
        }
        
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        vector<int> ans=mergeSort(nums1,nums2);
        
        int c=ans.size()-1;
        if((n+m)%2==0){
            
            int a=ans[c/2];
            int b=ans[c/2+1];
            
            return (double)(a+b)/2;
        }else{
           return (double)ans[(c)/2]; 
        }
        
    }
};