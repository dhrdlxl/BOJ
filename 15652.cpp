#include<iostream>
using namespace std;

void recursive(int N,int M,int count,int* answer,int start)
{
    if(M==count)
    {
        for(int i=0;i<M;i++)
        {
            cout<<answer[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    
    for(int i=start;i<=N;i++)
    {
        answer[count]=i;
        recursive(N,M,count+1,answer,i);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    int array[8];
    cin>>N>>M;

    recursive(N,M,0,array,1);
    return 0;
}