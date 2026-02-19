/*Given a m x n grid filled with non-negative numbers, find a path from top 
left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time. */

#include<iostream>
#include<vector>
using namespace std;
int solve(int i,int j,int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(i==0 && j==0){
        return grid[i][j];
    }
    if(i<0 || i>m || j<0 || j>n){
        return 1e9;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=grid[i][j]+solve(i-1,j,m,n,grid,dp);
    int left=grid[i][j]+solve(i,j-1,m,n,grid,dp);
    return dp[i][j]=min(up,left);
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>grid(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>dp(m,vector<int>(n,-1));
    int i=m-1,j=n-1;
    cout<<solve(i,j,m,n,grid,dp);
}