#include<iostream>
using namespace std;

int Y[3]={-1,-1,0};
int X[3]={0,-1,-1};
int map[1000][1000];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    int answer=0;
    bool check=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%1d",&map[i][j]);
            if(map[i][j]==1)
            {
                if(!check)check=true;
                if(i>0 && j>0)//좌상단 가로,세로 첫 줄 제외
                {
                    int min=1001;
                    for(int k=0;k<3;k++)
                    {
                        if(min>map[i+Y[k]][j+X[k]])
                            min = map[i+Y[k]][j+X[k]];
                    }
                    map[i][j]= min+1;
                    if(answer<map[i][j])
                        answer=map[i][j];
                }
            }
        }
    }
    if(answer==0 && check) answer=1;
    printf("%d",answer*answer);
    return 0;
}