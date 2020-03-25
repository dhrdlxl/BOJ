#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

struct node{
    int y;
    int x;
    int color;
    node(int a,int b,int c):y(a),x(b),color(c){}
};

int Y[4]={0,1,0,-1};
int X[4]={1,0,-1,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M,G,R;
    cin>>N>>M>>G>>R;
    int map[50][50];
    int mask[50][50][2];
    queue<node> groundCopy;//배양액을 뿌릴 수 있는 곳

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>map[i][j];
            if(map[i][j]==2)
                groundCopy.push(node(i,j,0));
        }
    }

    vector<int> permute(groundCopy.size());
    for(int i=0;i<G;i++)
    {
        permute[i]=2;
    }
    for(int i=G;i<G+R;i++)
    {
        permute[i]=1;
    }
    
    int answer=0;
    do{
        //mask 초기화
        memset(mask,-1,sizeof(mask));
        //배양액 분배
        queue<node> ground=groundCopy;
        for(int i=0;i<permute.size();i++)
        {
            int y = ground.front().y;
            int x = ground.front().x;
            ground.pop(); 
            if(permute[i]==2)
            {
                ground.push(node(y,x,0));//G
                mask[y][x][0]=0;
            }
            else if(permute[i]==1)
            {
                ground.push(node(y,x,1));//R
                mask[y][x][1]=0;
            }
        }
        int count=0;
        while(!ground.empty())
        {
            int y = ground.front().y;
            int x = ground.front().x;
            int color = ground.front().color;
            ground.pop();
            if(mask[y][x][color]!=-1 && mask[y][x][(color+1)%2]!=-1)
                continue;
            for(int i=0;i<4;i++)
            {
                int m_y = y+Y[i];
                int m_x = x+X[i];
                if(m_y>=0 && m_x>=0 && m_y<N && m_x<M)
                {
                    if(map[m_y][m_x]==1 || map[m_y][m_x]==2)//주위 땅
                    {
                        if(mask[m_y][m_x][color]==-1)
                        {
                            if(mask[m_y][m_x][(color+1)%2]==-1)//배양액이 아얘 없는 땅
                            {
                                mask[m_y][m_x][color]=mask[y][x][color]+1;
                                ground.push(node(m_y,m_x,color));
                            }
                            else//다른 색 배양액이 있을 때
                            {
                                if(mask[m_y][m_x][(color+1)%2]==mask[y][x][color]+1)//도달한 시점이 같을 때(꽃)
                                {
                                    count++;
                                    mask[m_y][m_x][color]=mask[y][x][color]+1;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(count>answer)answer=count;
    }while(prev_permutation(permute.begin(),permute.end()));
    
    cout<<answer;
    return 0;
}