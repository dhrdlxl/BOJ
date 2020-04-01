#include<iostream>
#include<vector>
using namespace std;

//각 인덱스에서 LIS를 모두 벡터에 저장
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int arr[1000];
    
    cin>>N;

    for(int i=0;i<N;i++)
        cin>>arr[i];

    int answer=0;
    int index=0;
    vector<vector<int>> dp(N);
    for(int i=0;i<N;i++)
    {
        dp[i].push_back(arr[i]);
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && dp[i].size()<dp[j].size()+1)
            {
                for(int k=dp[i].size();k>0;k--)
                {
                    dp[i].pop_back();
                }
                for(int k=0;k<dp[j].size();k++)
                {
                    dp[i].push_back(dp[j][k]);
                }
                dp[i].push_back(arr[i]);
            }
        }
        if(dp[i].size()>answer){
            answer=dp[i].size();
            index=i;
        }
    }
    cout<<answer<<'\n';
    for(int i=0;i<dp[index].size();i++)
    {
        cout<<dp[index][i]<<' ';
    }
    return 0;
}
