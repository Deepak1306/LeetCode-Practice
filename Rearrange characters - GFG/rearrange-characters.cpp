// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution
{
    public:
    
    char maxCount(vector<int>count){
        char ch;
        
        int max=0;
        for(int i=0;i<26;i++){
            if(count[i]>max){
                max=count[i];
                ch=i+'a';
            }
        }
        
        return ch;
    }
    
    string rearrangeString(string str)
    {
        //code here
        int n=str.length();
        if(n==0){
            return "";
        }
        
        vector<int>count(26,0);
        
        for(int i=0;i<n;i++){
            int j=str[i]-'a';
            count[j]++;
        }
        
        char maxCh=maxCount(count);
        int maxC=count[maxCh-'a'];
        
        if(maxC>(n+1)/2){
            return "-1";
        }
        string res(n,' ');
        
        int in=0;
        while(maxC>0){
            res[in]=maxCh;
            maxC--;
            in=in+2;
        }
        
        count[maxCh-'a']=0;
        
        for(int i=0;i<26;i++){
            while(count[i]>0){
                in=(in>=n)?1:in;
                res[in]=i+'a';
                in=in+2;
                count[i]--;
            }
        }
        
        return res;
        
    }
    
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  // } Driver Code Ends