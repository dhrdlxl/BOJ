#include<iostream>
using namespace std;
long long int dp[91];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;

    dp[1]=1;
    
    for(int i=2;i<=N;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];//n-1이 0인 경우 + n-1이 1인경우
    }
    cout<<dp[N];
    return 0;
}