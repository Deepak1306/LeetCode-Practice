class Solution {
public:

    // Encodes a URL to a shortened URL.
    string tinyUrl;
    string s;
    
    string encode(string longUrl) {
       int n=longUrl.length();
       tinyUrl=longUrl;
        
        int i=n-1;
        while(tinyUrl[i]!='/'){
            s=tinyUrl[i--]+s;
            tinyUrl.pop_back();
        }
        
        tinyUrl=tinyUrl+'$';
        
        return tinyUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int n=tinyUrl.length();
        while(tinyUrl[n-1]!='/'){
                tinyUrl.pop_back();
                n--;
              }
        tinyUrl=tinyUrl+s;
        return tinyUrl;
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));