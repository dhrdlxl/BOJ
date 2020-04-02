#include<iostream>
using namespace std;
int dp[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        dp[i]=i;
        for(int j=1;j*j<=i;j++)//j*j�� ���� ���� dp[0]=0�̹Ƿ� +1 �ؼ� 1�� �ȴ�
        {
            if(dp[i-j*j]<dp[i])
            {
                dp[i]=dp[i-j*j]+1;
            }
        }
    }
    cout<<dp[N];
    return 0;
}