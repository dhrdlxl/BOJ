#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case,n;
    int dp[11];
    cin>>test_case;
    
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int i=4;i<11;i++)
    {
        dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
    }
    while(test_case--)
    {
        int n;
        cin>>n;
        cout<<dp[n]<<'\n';
    }
    return 0;
}