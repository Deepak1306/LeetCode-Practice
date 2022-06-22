// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution
{
    public:
    
    char chara(vector<int>count){
    int c=count[0];
    char ch=0+'a';
    
    for(int i=1;i<26;i++){
        if(count[i]>c){
            c=count[i];
            ch=i+'a';
        }
    }
    
    return ch;
    
}
    
    string rearrangeString(string s)
    {
        //code here
       int n=s.length();
   
    
    vector<int>count(26,0);
    
    for(int i=0;i<n;i++){
        int c=s[i]-'a';
        count[c]++;
    }
    
    char ch=chara(count);
    int maxC=count[ch-'a'];
    
    
    if(maxC>(n+1)/2){
        return "-1";
    }
    
    string str(n,' ');
    int in=0;
    while(maxC>0){
        str[in]=ch;
        maxC--;
        in+=2;
    }
    count[ch-'a']=0;
    
    for(int i=0;i<26;i++){
        while(count[i]>0){
            in=(in>=n)?1:in;
            str[in]=i+'a';
            in+=2;
            count[i]--;
            
        }
    }
    
    return str;
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