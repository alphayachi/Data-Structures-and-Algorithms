#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long int  countPS(string str)
    {
        int n = str.length();
       long long int dp[n][n];
       for(int g=0; g<str.length(); g++){
           for(int i=0, j=g; j<str.length(); i++, j++){
               if(g==0){
                   dp[i][j]=1;
               }else if(g==1){
                   dp[i][j] = str[i] == str[j] ? 3 : 2;
               }else{
                   if(str[i]==str[j]){
                       dp[i][j] = (dp[i][j-1] + dp[i+1][j] + 1)%1000000007;
                   }else{
                       dp[i][j] = ((dp[i][j-1] + dp[i+1][j] -  dp[i+1][j-1])%1000000007 + 1000000007)%1000000007;
                   }
               }
           }
       }
       return dp[0][str.length()-1];
    }
     
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}