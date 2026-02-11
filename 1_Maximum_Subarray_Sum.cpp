/*Given an integer array nums, find the subarray with the largest sum, and return its sum*/
#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int maxSubarray(vector<int>&nums){
    int maxi=INT_MIN;
    int sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        sum=sum+nums[i];
        maxi=max(maxi,sum);
        if(sum<0){
            sum=0;
        }
        
    }
    return maxi;
}
int main(){
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<maxSubarray(nums);
    return 0;
}