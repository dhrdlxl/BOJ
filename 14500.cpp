#include<iostream>
#include<vector>
using namespace std;
short map[500][500];
vector<vector<pair<int, int>>> block(19);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin>>N>>M;
    block[0].push_back(make_pair(0,0));
    block[0].push_back(make_pair(1,0));
    block[0].push_back(make_pair(2,0));
    block[0].push_back(make_pair(3,0));
    block[1].push_back(make_pair(0,0));
    block[1].push_back(make_pair(0,1));
    block[1].push_back(make_pair(0,2));
    block[1].push_back(make_pair(0,3));
    block[2].push_back(make_pair(0,0));
    block[2].push_back(make_pair(0,1));
    block[2].push_back(make_pair(1,0));
    block[2].push_back(make_pair(1,1));
    block[3].push_back(make_pair(0,0));
    block[3].push_back(make_pair(0,1));
    block[3].push_back(make_pair(0,2));
    block[3].push_back(make_pair(1,2));
    block[4].push_back(make_pair(0,0));
    block[4].push_back(make_pair(0,1));
    block[4].push_back(make_pair(1,0));
    block[4].push_back(make_pair(2,0));
    block[5].push_back(make_pair(0,0));
    block[5].push_back(make_pair(1,0));
    block[5].push_back(make_pair(1,1));
    block[5].push_back(make_pair(1,2));
    block[6].push_back(make_pair(0,1));
    block[6].push_back(make_pair(1,1));
    block[6].push_back(make_pair(2,1));
    block[6].push_back(make_pair(2,0));
    block[7].push_back(make_pair(1,0));
    block[7].push_back(make_pair(1,1));
    block[7].push_back(make_pair(1,2));
    block[7].push_back(make_pair(0,2));
    block[8].push_back(make_pair(0,0));
    block[8].push_back(make_pair(0,1));
    block[8].push_back(make_pair(1,1));
    block[8].push_back(make_pair(2,1));
    block[9].push_back(make_pair(0,0));
    block[9].push_back(make_pair(1,0));
    block[9].push_back(make_pair(0,1));
    block[9].push_back(make_pair(0,2));
    block[10].push_back(make_pair(0,0));
    block[10].push_back(make_pair(1,0));
    block[10].push_back(make_pair(2,0));
    block[10].push_back(make_pair(2,1));
    block[11].push_back(make_pair(0,0));
    block[11].push_back(make_pair(0,1));
    block[11].push_back(make_pair(1,1));
    block[11].push_back(make_pair(1,2));
    block[12].push_back(make_pair(1,0));
    block[12].push_back(make_pair(2,0));
    block[12].push_back(make_pair(0,1));
    block[12].push_back(make_pair(1,1));
    block[13].push_back(make_pair(1,0));
    block[13].push_back(make_pair(0,1));
    block[13].push_back(make_pair(1,1));
    block[13].push_back(make_pair(0,2));
    block[14].push_back(make_pair(0,0));
    block[14].push_back(make_pair(1,0));
    block[14].push_back(make_pair(1,1));
    block[14].push_back(make_pair(2,1));
    block[15].push_back(make_pair(0,0));
    block[15].push_back(make_pair(1,0));
    block[15].push_back(make_pair(2,0));
    block[15].push_back(make_pair(1,1));
    block[16].push_back(make_pair(1,0));
    block[16].push_back(make_pair(0,1));
    block[16].push_back(make_pair(1,1));
    block[16].push_back(make_pair(1,2));
    block[17].push_back(make_pair(1,0));
    block[17].push_back(make_pair(0,1));
    block[17].push_back(make_pair(1,1));
    block[17].push_back(make_pair(2,1));
    block[18].push_back(make_pair(0,0));
    block[18].push_back(make_pair(0,1));
    block[18].push_back(make_pair(1,1));
    block[18].push_back(make_pair(0,2));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>map[i][j];
        }
    }

    int answer=0;
    int sum=0;
    for(int i=0;i<19;i++)
    {
        for(int y=0;y<N;y++)
        {
            for(int x=0;x<M;x++)
            {
                sum=0;
                for(int k=0;k<block[i].size();k++)
                {
                    if(y+block[i][k].second>=N || x+block[i][k].first>=M)
                    {
                        sum=0;
                        break;
                    }
                    sum+=map[y+block[i][k].second][x+block[i][k].first];
                }
                if(sum>answer)answer=sum;
            }
        }
    }
    cout<<answer;
    return 0;
}