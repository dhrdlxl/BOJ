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
    {
        cin>>arr[i];
    }

    int answer=arr[0];
    for(int i=0;i<N;i++)
    {
        dp[i]=arr[i];
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && dp[i]<dp[j]+arr[i])
            {
                dp[i] = dp[j]+arr[i];
            }
        }
        if(dp[i]>answer)answer=dp[i];
    }

    cout<<answer;
    return 0;
}