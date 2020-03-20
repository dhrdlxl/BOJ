#include<iostream>
#include<queue>
using namespace std;

int Y[4]={0,1,0,-1};
int X[4]={1,0,-1,0};
int box[1000][1000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h,w;
    cin>>w>>h;

    queue<pair<int,int>> q;
    
    int XRipeTomatoCount=0;//익지 않은 토마토 수
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>box[i][j];
            if(box[i][j]==1)
            {
                q.push(make_pair(i,j));
            }
            else if(box[i][j]==0)
                XRipeTomatoCount++;
        }
    }

    int answer=1;

    while(!q.empty())
    {
        for(int i=0;i<4;i++)
        {
            int y = q.front().first + Y[i];
            int x = q.front().second + X[i];
            if(y>=0 && x>=0 && y<h && x<w)
            {
                if(box[y][x]==0)
                {
                    box[y][x]= box[q.front().first][q.front().second]+1;
                    if(answer<box[y][x])
                        answer = box[y][x];
                    XRipeTomatoCount--;
                    q.push(make_pair(y,x));
                }
            }
        }
        q.pop();
    }
    if(XRipeTomatoCount==0)
    {
        cout<<answer-1;
    }
    else
    {
        cout<<-1;
    }
    
    return 0;
}