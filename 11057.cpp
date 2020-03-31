#include <iostream>
using namespace std;

int dp[1001][10];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    for(int i=0;i<10;i++)
        dp[1][i]=1;
    
    for(int i=2;i<=N;i++)
    {
        dp[i][0]=1;
        for(int j=1;j<10;j++)
        {
            dp[i][j]=(dp[i][j-1]+dp[i-1][j])%10007;
        }
    }

    int answer=0;
    for(int i=0;i<10;i++)
    {
        answer+=dp[N][i];
    }
    cout<<answer%10007;
    return 0;
}