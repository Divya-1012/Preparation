/*You are given an m x n integer array grid. There is a robot initially located at the top-left corner 
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can 
only move either down or right at any point in time.An obstacle and space are marked as 1 or 0 respectively in
 grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.*/

#include<iostream>
#include<vector>
using namespace std;
int solve(int i,int j,int m,int n,vector<vector<int>>&dp,vector<vector<int>>v){
    if(i>=0 && j>=0 && v[i][j]==1){
        return 0;
    }
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=solve(i-1,j,m,n,dp,v);
    int left=solve(i,j-1,m,n,dp,v);
    return dp[i][j]=up+left;
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>v(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>>dp(m,vector<int>(n,-1));
    int a=m-1;
    int b=n-1;
    cout<<solve(a,b,m,n,dp,v);
}
