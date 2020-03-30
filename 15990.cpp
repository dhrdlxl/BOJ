#include<iostream>
using namespace std;

const int MAX = 100000;
int dp[MAX+1][4];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case,N;
    cin>>test_case;
    dp[1][1]=1;
    dp[1][2]=0;
    dp[1][3]=0;
    dp[2][1]=0;
    dp[2][2]=1;
    dp[2][3]=0;
    dp[3][1]=1;
    dp[3][2]=1;
    dp[3][3]=1;

    for(int i=4;i<=MAX;i++)
    {
        for(int j=1;j<=3;j++)
        {
            for(int k=1;k<=3;k++)
            {
                if(j!=k) 
                    dp[i][j]=(dp[i][j]+dp[i-j][k])%1000000009;
            }
        }
    }

    while(test_case--)
    {
        cin>>N;
        cout<<((dp[N][1]+dp[N][2])%1000000009+dp[N][3])%1000000009<<'\n';
    }
    return 0;
}