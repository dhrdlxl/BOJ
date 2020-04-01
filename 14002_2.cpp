#include<iostream>
using namespace std;

void recursive(int ind,int* arr,int* indexArr)
{
    if(indexArr[ind]!=-1)
        recursive(indexArr[ind],arr,indexArr);
    cout<<arr[ind]<<' ';
    return;
}

//Index배열에 앞에 연결된 LIS index 저장
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    int arr[1000];
    int dp[1000];
    int index[1000];

    cin>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];

    int answer=0;
    int ind=0;
    for(int i=0;i<N;i++)
    {
        dp[i]=1;
        index[i]=-1;
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                index[i]=j;
            }
        }
        if(answer<dp[i])
        {
            answer=dp[i];
            ind = i;
        }
    }

    cout<<answer<<'\n';
    recursive(ind,arr,index);
    return 0;
}