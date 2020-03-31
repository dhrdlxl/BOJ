#include<iostream>
using namespace std;
int dp[101][10];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;

    for(int i=1;i<=9;i++)
        dp[1][i]=1;
    
    for(int i=2;i<=N;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(j-1>=0)
                dp[i][j]=(dp[i][j]+dp[i-1][j-1])%1000000000;
            if(j+1<=9)
                dp[i][j]=(dp[i][j]+dp[i-1][j+1])%1000000000;
        }
    }
    int answer=0;
    for(int i=0;i<=9;i++)
    {
        answer = (answer+dp[N][i])%1000000000;
    }
    cout<<answer;
    return 0;
}