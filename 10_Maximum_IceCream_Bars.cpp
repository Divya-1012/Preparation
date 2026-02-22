/*It is a sweltering summer day, and a boy wants to buy some ice cream bars.At the store, there are n ice cream 
bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The
 boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 
Note: The boy can buy the ice cream bars in any order.
Return the maximum number of ice cream bars the boy can buy with coins coins.*/

#include<iostream>     
#include<vector>
#include<algorithm>
using namespace std;
int maxIceCream(vector<int>& costs, int coins) {
         if(coins==0){
            return 0;
        }
        sort(costs.begin(),costs.end());
        int n=costs.size();
        int c=0;
        for(int i=0;i<n;i++){
            coins=coins-costs[i];
            if(coins<0){
                break;
            }
            else{
                c++;
            }
        }
        return c;
    }   
int main(){
    int n,coins;
    cin>>n>>coins;
    vector<int>costs(n);
    for(int i=0;i<n;i++){
        cin>>costs[i];
    }

    cout<<maxIceCream(costs,coins);
    return 0;   
}