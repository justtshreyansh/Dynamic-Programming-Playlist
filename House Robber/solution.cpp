#include<bits/stdc++.h>
using namespace std;
int recursive(vector<int> &arr,int n,int i){
    if(i>=n) return 0;

    return max(recursive(arr,n,i+2) + arr[i],recursive(arr,n,i+1));
}

int memoization(vector<int> &arr,int n,int i,vector<int> &dp){
    if(i>=n) return 0;

    if(dp[i]!=-1){
        return dp[i];
    }

    return dp[i] = max(memoization(arr,n,i+2,dp) + arr[i],memoization(arr,n,i+1,dp));
}

int tabulation(vector<int> &arr,int n,int i){
    if(n == 0) return 0;
    if(n == 1) return arr[0];

    vector<int> dp(n, 0);

    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for(int i = 2; i < n; i++){
        int pick = arr[i] + dp[i-2];
        int notPick = dp[i-1];

        dp[i] = max(pick, notPick);
    }   

    return dp[n-1];
}
int main(){
    vector<int>  arr = {2,7,9,3,1};
    int n = arr.size();
    int i=0;
    vector<int> dp(n+1,-1);
    int first = memoization(arr,n,0,dp);
    int second = memoization(arr,n,1,dp);

    
    
   cout<<max(first,second)<<endl;

    return 0;
}