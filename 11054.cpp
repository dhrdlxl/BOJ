#include<iostream>
using namespace std;

int arr[1001];
int Idp[1001];//Increase
int Ddp[1001];//Decrease
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<N;i++)
    {
        Idp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && Idp[i]<Idp[j]+1)
            {
                Idp[i]=Idp[j]+1;
            }
        }
    }
    for(int i=N-1;i>=0;i--)
    {
        Ddp[i]=1;
        for(int j=N-1;j>i;j--)
        {
            if(arr[i]>arr[j] && Ddp[i]<Ddp[j]+1)
            {
                Ddp[i]=Ddp[j]+1;
            }
        }
    }
    int answer=0;
    for(int i=0;i<N;i++)
    {
        if(answer<Idp[i]+Ddp[i])
            answer = Idp[i] + Ddp[i];
    }
    cout<<answer-1;
    return 0;
}