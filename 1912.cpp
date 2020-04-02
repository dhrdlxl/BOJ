#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int dp[100001];
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>dp[i];
    }
    int answer=dp[0];
    for(int i=1;i<n;i++)
    {
        if(dp[i]<dp[i-1]+dp[i]){
            dp[i]=dp[i-1]+dp[i];
        }
        if(answer<dp[i])
            answer=dp[i];
    }
    cout<<answer;
    return 0;
}