class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size();
        int m=word2.size();
        
        for(int i=1;i<n;i++){
            word1[i]=word1[i-1]+word1[i];
        }
        
        for(int i=1;i<m;i++){
            word2[i]=word2[i-1]+word2[i];
        }
        
        return word1[n-1]==word2[m-1];
    }
};