#include<iostream>

using namespace std;

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
        for(int j=i;j+i<=N;j++)
        {
            if(P[i+j]<P[i]+P[j])
                P[i+j]=P[i]+P[j];
        }
    }
    cout<<P[N];
    return 0;
}