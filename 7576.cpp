#include<iostream>
#include<queue>
using namespace std;
int farm[1001][1001];
int test_y[4]={-1,0,1,0};
int test_x[4]={0,1,0,-1};
int main(){
    cin.sync_with_stdio(false);
    
    queue<pair<int,int>> Ripe;
    int M,N;
    int RipeCount=0;
    int empty=0;
    cin>>M>>N;
    for(int j=0;j<N;j++)
    {
        for(int i=0;i<M;i++)
        {
            cin>>farm[j][i];
            if(farm[j][i]==1)
            {
                Ripe.push(make_pair(j,i)); 
                RipeCount++;
            }
            else if(farm[j][i]==-1) empty++;
        }
    }
    
    int x,y;
    int count=0;
    int answer=0;
    int queue_size=0;
    while(!Ripe.empty())
    {
        count=0;
        queue_size=Ripe.size();
        while(queue_size>0)
        {
            queue_size--;
            y=Ripe.front().first;
            x=Ripe.front().second;
            Ripe.pop();
            for(int i=0;i<4;i++)
            {
                if(test_y[i]+y>=0 && test_y[i]+y<N && test_x[i]+x>=0 && test_x[i]+x<M)
                {
                    if(farm[test_y[i]+y][test_x[i]+x]==0)
                    {
                        farm[test_y[i]+y][test_x[i]+x]=1;
                        count++;
                        RipeCount++;
                        Ripe.push(make_pair(test_y[i]+y,test_x[i]+x));
                    }
                }
            }
        }
        if(count>0)answer++;      
    }
    
    if(RipeCount+empty!=N*M) cout<<-1;
    else cout<<answer;
    return 0;
}