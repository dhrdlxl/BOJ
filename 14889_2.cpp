#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int map[20][20];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,answer=10000;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>map[i][j];
        }
    }

    vector<int> permute(N);
    for(int i=0;i<N/2;i++)
    {
        permute[i]=1;
    }

    do{
        vector<int> teamA;
        vector<int> teamB;
        for(int i=0;i<N;i++)
        {
            if(permute[i]==1)
                teamA.push_back(i);
            else
                teamB.push_back(i);
        }

        int a=0,b=0;
        for(int i=0;i<N/2;i++)
        {
            for(int j=0;j<N/2;j++)
            {
                a+=map[teamA[i]][teamA[j]];
                b+=map[teamB[i]][teamB[j]];
            }
        }
        int sub=a-b;
        if(sub<0)sub*=-1;
        if(answer>sub)answer=sub;
    }while(prev_permutation(permute.begin(),permute.end()));
    
    cout<<answer;
    return 0;
}