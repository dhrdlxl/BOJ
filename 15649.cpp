#include<iostream>
#include<vector>
using namespace std;

void recursive(vector<int> Sequence,int Bitmask,int N,int M)
{
    if(Sequence.size()==M)
    {
        for(int i=0;i<Sequence.size();i++)
        {
            cout<<Sequence[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i=0;i<N;i++)
    {
        if((Bitmask&(1<<i))==0)
        {
            Sequence.push_back(i+1);
            recursive(Sequence,Bitmask|(1<<i),N,M);
            Sequence.pop_back();
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;

    cin>>N>>M;
    vector<int> vec;
    
    recursive(vec,0,N,M);
    return 0;
}