/*You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/
#include<iostream>
#include<vector>
using namespace std;
int solve(int n,vector<int>&dp){
    if(n==0||n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int left=solve(n-1,dp);
    int right=solve(n-2,dp);
    return dp[n]=left+right;
}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<solve(n,dp);
    return 0;
}