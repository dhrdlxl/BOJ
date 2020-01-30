#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    short E,S,M;
    short e=0,s=0,m=0;
    cin>>E>>S>>M;

    for(int answer=1;answer<7981;answer++)
    {
        e=e%15+1;
        s=s%28+1;
        m=m%19+1;
        if(E==e && S==s && M==m)
            cout<<answer;
    }
    return 0;
}