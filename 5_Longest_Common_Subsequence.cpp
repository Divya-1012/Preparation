/* Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common 
subsequence, return 0. A subsequence of a string is a new string generated from the original string with some 
characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int solve(int m,int n,string s,string t,vector<vector<int>>dp){
    if(n==0 || m==0){
        return 0;
    }
    if(dp[m][n]!=-1){
        return dp[n][m];
    }
    if(s[m]==t[n]){
        return dp[m][n]=1+solve(m-1,n-1,s,t,dp);
    }
    return dp[m][n]=max(solve(m-1,n,s,t,dp),solve(m,n-1,s,t,dp));
}
int main(){
    string text1,text2;
    cin>>text1;
    cin>>text2;
    int m=text1.size();
    int n=text2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    cout<<solve(m,n,text1,text2,dp);
    return 0;

}