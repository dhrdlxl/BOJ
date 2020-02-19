#include<iostream>
#include<algorithm>
using namespace std;

void recursive(int N,int M,int* arr,int* answer,int count,int start)
{
    if(count==M)
    {
        for(int i=0;i<M;i++)
        {
            cout<<answer[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=start;i<N;i++)
    {
        answer[count]=arr[i];
        recursive(N,M,arr,answer,count+1,i);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    int nums[8];
    int answer[8];
    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>nums[i];
    
    sort(nums,nums+N);

    recursive(N,M,nums,answer,0,0);    

    return 0;
}