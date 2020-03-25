#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int dp[1001];
    cin>>n;

    dp[1]=1;
    dp[2]=3;

    for(int i=3;i<=n;i++)
    {
        dp[i]=(dp[i-2]*2+dp[i-1])%10007;
    }
    cout<<dp[n];
    return 0;
}