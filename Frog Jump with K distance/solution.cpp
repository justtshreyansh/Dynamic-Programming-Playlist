#include <bits/stdc++.h>
using namespace std;
int recursive(vector<int> &heights, int n, int k)
{
    if (n == 0)
        return 0;
    int mini = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int val = recursive(heights, n - i, k) + abs(heights[n] - heights[n - i]);
            mini = min(mini, val);
        }
    }
    return mini;
}
int memoization(vector<int> &heights,int n,int k,vector<int> &dp){
    if(n==0) return 0;

    if(dp[n]!=-1) return dp[n];

    int mini = INT_MAX;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            int val = memoization(heights,n-i,k,dp) + abs(heights[n]-heights[n-i]);
            mini = min(mini,val);
           
        }
    }
    return dp[n] = mini;
}
int tabulation(vector<int> &heights,int n,int k,vector<int> &dp){
    dp[0] = 0;
    
    for(int i=1;i<n;i++){
        int mini = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int val = dp[i-j] + abs(heights[i]-heights[i-j]);
                mini = min(mini,val);
            }
        }
        dp[i] = mini;
    }   
    return dp[n-1];
}
int frogJump(vector<int> &heights,int k,vector<int> &dp)
{
    return tabulation(heights,heights.size(),k,dp);
}
int main()
{
    vector<int> heights = {10, 30, 40, 50, 20};
    int k = 3;
    vector<int> dp(heights.size()+1,-1);
    cout<<frogJump(heights,k,dp)<<endl;

    return 0;
}