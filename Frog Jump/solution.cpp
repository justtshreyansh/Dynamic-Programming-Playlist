#include<bits/stdc++.h>
using namespace std;

int recursive(vector<int> &heights,int n){
    if(n==0){
        return 0;
    }

    int left = recursive(heights,n-1) + abs(heights[n] - heights[n-1]);
    int right = n-2>=0 ? recursive(heights,n-2) + abs(heights[n] - heights[n-2]): INT_MAX;
    return min(left,right);
}

int memoization(vector<int> &heights,int n,vector<int> &dp){
    if(n==0) return 0;

    if(dp[n]!=-1){
        return dp[n];
    }

    int left = memoization(heights,n-1,dp) + abs(heights[n]-heights[n-1]);
    int right = INT_MAX;
    if(n-2>=0){
        right = memoization(heights,n-2,dp) + abs(heights[n]-heights[n-2]);
    }
    dp[n] = min(left,right);
    return dp[n];
}
int tabulation(vector<int> &heights,int n,vector<int> &dp){
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int left = dp[i-1] + abs(heights[i]-heights[i-1]);
        int right= INT_MAX;
        if(i>=2){
            right= dp[i-2] + abs(heights[i]-heights[i-2]);
        }
        dp[i] = min(left,right);
    }
    return dp[n];
}
int spaceOptimization(vector<int> &heights,int n){
    if(n==0) return 0;

    int prev2 = 0;
    int prev = abs(heights[1] - heights[0]);
    for(int i=2;i<=n;i++){
        int left =(prev + abs(heights[i]-heights[i-1]));
        int right = INT_MAX;
        if(i>=2)
         right = prev2 + abs(heights[i] - heights[i-2]);
        int next = min(right,left);
        prev2 = prev;
        prev = next;

    }
    return prev;
}
int frogJump(vector<int> &heights,vector<int> &dp){
    return spaceOptimization(heights,heights.size()-1);
}
int main(){
    vector<int> heights = {20,30,40,20};
    vector<int> dp(heights.size()+1,-1);
    cout<<frogJump(heights,dp)<<endl;
    return 0;
}