#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,S;
    cin>>N>>S;

    int array[20];
    for(int i=0;i<N;i++)
        cin>>array[i];
    int Max = (1<<N)-1;
    int answer=0;
    for(int i=1;i<=Max;i++)
    {
        int sum=0;
        for(int j=0;j<N;j++)
        {
            if(i&(1<<j))
            {
                sum+=array[j];
            }
        }
        if(sum==S)answer++;
    }
    cout<<answer;
    return 0;
}