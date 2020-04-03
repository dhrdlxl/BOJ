#include<iostream>
using namespace std;

long long int dp[201][201];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K;
    cin>>N>>K;

    for(int i=0;i<=N;i++)//k==1
        dp[i][1]=1;
    
    for(int i=2;i<=K;i++)
    {
        for(int j=0;j<=N;j++)
        {
            if(j==0)
                dp[j][i]=dp[j][i-1]%1000000000;
            else
            {
                dp[j][i]=(dp[j-1][i]+dp[j][i-1])%1000000000;
            }
        }
    }
    cout<<dp[N][K];

    return 0;
}