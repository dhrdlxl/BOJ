#include<iostream>
using namespace std;

void recursive(int N,int M,int count,int answer[7])
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
    
    for(int i=1;i<=N;i++)
    {
        answer[count]=i;
        recursive(N,M,count+1,answer);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    int array[7];
    cin>>N>>M;

    recursive(N,M,0,array);
    return 0;
}