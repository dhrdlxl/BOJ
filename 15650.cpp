#include<iostream>
using namespace std;

void recursive(int N,int M,int count,int answer,int num)
{
    if(count==M)
    {
        for(int i=0;i<N;i++)
        {
            if(answer&(1<<i))
                cout<<i+1<<' ';
        }
        cout<<'\n';
        return;
    }
    if(num==N) return;
    recursive(N,M,count+1,answer|(1<<num),num+1);
    recursive(N,M,count,answer,num+1);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;

    cin>>N>>M;

    recursive(N,M,0,0,0);
    return 0;
}