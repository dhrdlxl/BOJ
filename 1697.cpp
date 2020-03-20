#include<iostream>
#include<queue>
using namespace std;

int road[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K;
    cin>>N>>K;

    queue<int> q;
    q.push(N);

    road[N]=0;
    while(!q.empty())
    {
        if(q.front() == K)break;
        int pos = q.front();
        if(pos-1>=0)
        {            
            if(road[pos-1]==0){
                road[pos-1]=road[pos]+1;
                q.push(pos-1);
            }
        }
        if(pos+1<=K)
        {
            if(road[pos+1]==0){
                q.push(pos+1);
                road[pos+1]=road[pos]+1;
            }
       }
        if(pos*2<=100000 && pos<K)
        {
            
            if(road[pos*2]==0){
                road[pos*2]=road[pos]+1;
                q.push(pos*2);
            }
        }
        q.pop();
    }

    cout<<road[K];
    return 0;
}