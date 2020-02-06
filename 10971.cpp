#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int cost[10][10];
    int array[10];
    cin>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>cost[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        array[i]=i;
    }

    int answer=2e9;
    do{
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(cost[array[i]][array[(i+1)%n]]==0)
            {
                sum=2e9;
                break;
            }
            sum+=cost[array[i]][array[(i+1)%n]];
        }
        if(sum<answer)answer=sum;
    }while(next_permutation(array,array+n));

    cout<<answer;
    return 0;
}