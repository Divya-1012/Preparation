/*There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either
 down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the
 bottom-right corner.The test cases are generated so that the answer will be less than or equal to 2 * 10^9.*/

 #include<iostream>
 #include<vector>
 using namespace std;
 int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=solve(i-1,j,m,n,dp);
    int left=solve(i,j-1,m,n,dp);
    return dp[i][j]=up+left;
 }
 int main(){
    int m,n;
    cin>>m>>n;
    int i=m-1,j=n-1;
    vector<vector<int>>dp(m,vector<int>(n,-1));
    cout<<solve(i,j,m,n,dp);
    return 0;
 }
