#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,K;
    int mask[200001];
    queue<int> now,next;

    cin>>N>>K;
    memset(mask,-1,sizeof(mask));

    now.push(N);
    mask[N]=0;

    while(!now.empty())
    {
        int visit = now.front();
        now.pop();

        //*2
        if(visit*2<K*2)
        {
            if(mask[visit*2]==-1)
            {
                now.push(visit*2);
                mask[visit*2]=mask[visit];
            }
        }

        //-1
        if(visit-1>=0)
        {
            if(mask[visit-1]==-1)
            {
                next.push(visit-1);
                mask[visit-1]=mask[visit]+1;
            }
        }

        //+1
        if(visit+1<=K)
        {
            if(mask[visit+1]==-1)
            {
                next.push(visit+1);
                mask[visit+1]=mask[visit]+1;
            }
        }

        if(now.empty())
        {
            now=next;
            next = queue<int>();
        }
    }
    cout<<mask[K];
    return 0;
}