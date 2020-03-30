#include<iostream>
using namespace std;

int min(int a,int b)
{
    if(a<b)return a;
    return b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    int P[1001];

    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>P[i];
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i/2;j++)
        {
            P[i]=min(P[i],P[j]+P[i-j]);
        }
    }
    cout<<P[N];
    return 0;
}