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
        dp[i]=dp[i-1]+dp[i-2];//n-1�� 0�� ��� + n-1�� 1�ΰ��
    }
    cout<<dp[N];
    return 0;
}