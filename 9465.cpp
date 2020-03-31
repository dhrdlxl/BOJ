#include<iostream>
using namespace std;

int max(int a,int b)
{
    if(a>b) return a;
    return b;
}

int dp[2][100000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case, n;
    cin>>test_case;

    while(test_case--)
    {
        cin>>n;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>dp[i][j];
            }
        }

        for(int i=1;i<n;i++)
        {
            if(i-2>=0)
            {
                dp[0][i]+=max(dp[1][i-2],dp[1][i-1]);
                dp[1][i]+=max(dp[0][i-2],dp[0][i-1]);
            }
            else
            {
                dp[0][i]+=dp[1][i-1];
                dp[1][i]+=dp[0][i-1];
            }
        }
        cout<<max(dp[0][n-1],dp[1][n-1])<<'\n';
    }
    return 0;
}