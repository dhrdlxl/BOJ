#include<iostream>
using namespace std;

int dp[1000001];

int top_down(int n)
{
    
    if(n==1) return 0;
    if(dp[n]>0) return dp[n];
    dp[n]=top_down(n-1)+1;
    if(n%2==0)
    {
        int x = top_down(n/2)+1;
        if(dp[n]>x)dp[n]=x;
    }
    if(n%3==0)
    {
        int x = top_down(n/3)+1;
        if(dp[n]>x)dp[n]=x;
    }
    return dp[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;

    cout<<top_down(N);
    return 0;
}