/*Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without 
changing the order of the remaining elements.*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int lps(string s){
    int n=s.size();
    string t=s;
    reverse(t.begin(),t.end());
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n][n];

}
int main(){
    string s;
    cin>>s;
    cout<<lps(s);
    return 0;
}