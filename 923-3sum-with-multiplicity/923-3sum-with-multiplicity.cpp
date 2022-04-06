class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n=arr.size();
        int mod=1e9+7;
        
        int count=0;
        
        sort(arr.begin(),arr.end());
        
        for(int k=0;k<n;k++){
          int c=target-arr[k];
            
            int i=k+1;
            int j=n-1;
            
            while(i<j){
                
                if(arr[i]+arr[j]>c){
                    j--;
                }else if(arr[i]+arr[j]<c){
                    i++;
                }else{
                    if(arr[i]==arr[j]){
                        count=(count+((j-i)*(j-i+1))/2)%mod;
                        break;
                    }else{
                        int i1=i+1;
                        int j1=j-1;
                        
                        while(i1<=j1 && arr[i1]==arr[i]){
                            i1++;
                        }
                        while(i1<=j1 && arr[j1]==arr[j]){
                            j1--;
                        }
                        
                        count=(count+(i1-i)*(j-j1))%mod;
                        i=i1;
                        j=j1;
                        
                    }    
                    
                    
                }
                
            }
        }
        
        return count%mod;
    }
};