#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;
int MAX = 1000;
int mask[1001][1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int S, count=1, clipboard=0;
    queue<pair<int,int>> q;
    cin>>S;

    q.push(make_pair(count,clipboard));
    memset(mask,-1,sizeof(mask));
    mask[1][0]=0;
    while(!q.empty())
    {
        count = q.front().first;
        clipboard = q.front().second;
        q.pop();

        //copy 
        if(mask[count][count]==-1)
        {
            mask[count][count]=mask[count][clipboard]+1;
            q.push(make_pair(count,count));
        }

        //paste
        if(clipboard!=0 && count+clipboard<=S)
        {
            if(mask[count+clipboard][clipboard]==-1)
            {
                mask[count+clipboard][clipboard] = mask[count][clipboard]+1;
                q.push(make_pair(count+clipboard,clipboard));
            }
        }

        //delete
        if(count-1>=2)
        {
            if(mask[count-1][clipboard]==-1)
            {
                mask[count-1][clipboard]= mask[count][clipboard]+1;
                q.push(make_pair(count-1,clipboard));
            }
        }
    }

    int answer=MAX;
    for(int i=0;i<MAX;i++)
    {
        if(answer>mask[S][i] && mask[S][i]!=-1)
            answer = mask[S][i];
    }
    cout<<answer;
    return 0;
}