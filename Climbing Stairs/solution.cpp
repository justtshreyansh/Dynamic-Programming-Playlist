#include<bits/stdc++.h>
using namespace std;
int recursion(int n){
    if(n==0 || n==1){
        return 1;
    }

    return recursion(n-1) + recursion(n-2);
}

int memoization(int n,vector<int> &dp){
    if(n==0 || n==1){
        return 1;
    }

    if(dp[n]!=-1) return dp[n];

    dp[n] = memoization(n-1,dp) + memoization(n-2,dp);
    return dp[n];
}

int tabulation(int n,vector<int> &dp){
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int spaceOptimization(int n){
    if(n==0 || n==1) return 1;

    int prev2 = 1;
    int prev = 1;
    for(int i=2;i<=n;i++){
        int next = prev2 + prev;
        prev2 = prev;
        prev = next;

    }

    return prev;


}
int climbingStairs(int n,vector<int> &dp){
    return spaceOptimization(n);
}
int main(){
    int n = 5;
    vector<int> dp(n+1,-1);
    cout<<climbingStairs(n,dp)<<endl;
    return 0;
}