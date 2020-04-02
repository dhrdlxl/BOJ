#include<iostream>

using namespace std;
int arr[100001];
int dp_front[100001];
int dp_back[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int answer=arr[0];
    for(int i=0,j=n-1;i<n;i++,j--)
    {
        dp_front[i]=arr[i];
        dp_back[j]=arr[j];
        if(i!=0)
        {
            if(dp_front[i]<dp_front[i-1]+arr[i])
            {
                dp_front[i]=dp_front[i-1]+arr[i];
            }

            if(dp_back[j]<dp_back[j+1]+arr[j])
            {
                dp_back[j]=dp_back[j+1]+arr[j];
            }
        }
        if(answer<dp_front[i])answer=dp_front[i];
    }

    for(int i=1;i<n-1;i++)
    {
        if(answer<dp_front[i-1]+dp_back[i+1])
            answer=dp_front[i-1]+dp_back[i+1];
    }
    cout<<answer;
    return 0;
}