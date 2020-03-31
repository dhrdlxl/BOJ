#include<iostream>
using namespace std;
long long int dp[91][2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;

    dp[1][0]=0;
    dp[1][1]=1;
    
    for(int i=2;i<=N;i++)
    {
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    cout<<dp[N][0]+dp[N][1];
    return 0;
}