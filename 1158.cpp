#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    short N,K;
    queue<short> cycle;

    cin>>N>>K;
    for(int i=1;i<=N;i++)cycle.push(i);
    
    cout<<'<';
    for(int j=0;j<N-1;j++)
    {
        for(int i=0;i<K-1;i++)
        {
            cycle.push(cycle.front());
            cycle.pop();
        }
        cout<<cycle.front()<<", ";
        cycle.pop();
    }
    cout<<cycle.front()<<'>';
    return 0;
}