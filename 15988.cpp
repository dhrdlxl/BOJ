#include<iostream>

using namespace std;
int dp[1000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case,n;
    
    cin>>test_case;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int i=4;i<=1000000;i++)
    {
        dp[i]= ((dp[i-3]+dp[i-2])%1000000009+dp[i-1])%1000000009;
    }
    while(test_case--)
    {
        cin>>n;
        cout<<dp[n]<<'\n';
    }
    return 0;
}