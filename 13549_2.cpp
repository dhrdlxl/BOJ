#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K;
    int mask[200001];
    deque<int> dq;

    cin>>N>>K;
    memset(mask,-1,sizeof(mask));

    dq.push_back(N);
    mask[N]=0;

    while(!dq.empty())
    {
        int now = dq.front();
        dq.pop_front();

        //2*X
        if(now*2 <K*2)
        {
            if(mask[now*2]==-1)
            {
                dq.push_front(now*2);
                mask[now*2]=mask[now];
            }
        }

        //X-1
        if(now-1>=0)
        {
            if(mask[now-1]==-1)
            {
                dq.push_back(now-1);
                mask[now-1]=mask[now]+1;
            }
        }

        //X+1
        if(now+1<=K)
        {
            if(mask[now+1]==-1)
            {
                dq.push_back(now+1);
                mask[now+1]=mask[now]+1;
            }
        }
    }

    cout<<mask[K];
    return 0;
}