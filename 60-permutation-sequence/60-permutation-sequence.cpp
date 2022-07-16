class Solution {
public:
    string getPermutation(int A, int B) {
         string ans="";
     long long int fact=1;
     vector<int>arr;
     for(int i=1;i<A;i++){
         fact=fact*i;
         arr.push_back(i);
     }
     arr.push_back(A);
     B=B-1;
     while(true){
         int k=B/fact;
         char c=arr[k]+'0';
         ans.push_back(c);
         arr.erase(arr.begin()+k);
         if(arr.size()==0){
             break;
         }
         B=B%fact;
         fact=fact/arr.size();
     }
     return ans;
    }
};