#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int arr[1000];
    int dp[1000];

    cin>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];

    int answer=0;
    for(int i=0;i<N;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[i]<arr[j] && dp[i]<dp[j]+1)
            {
                dp[i] = dp[j]+1;
            }
        }
        if(dp[i]>answer)answer=dp[i];
    }
    cout<<answer;
    return 0;
}