#include<iostream>
using namespace std;

int max(int a,int b)
{
    return a>b? a:b;
}

int arr[10000];
int dp[10000][2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>arr[i];
    dp[0][0]=0;
    dp[0][1]=arr[0];
    for(int i=1;i<n;i++)
    {
        //안마실 때
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);

        //마실 때
        if(i==1)
        {
            dp[i][1]=dp[i-1][1]+arr[i];
        }
        else
        {
            dp[i][1]=max(dp[i-1][0],dp[i-2][0]+arr[i-1])+arr[i];
        }
    }
    cout<<max(dp[n-1][0],dp[n-1][1]);
    return 0;
}