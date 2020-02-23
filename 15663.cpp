#include<iostream>
#include<algorithm>
using namespace std;

void recursive(int N,int M,int* nums,int* numCount,int index,int* answer)
{
    if(index==M)
    {
        for(int i=0;i<M;i++)
        {
            cout<<answer[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<N;i++)
    {
        if(numCount[i]>0)
        {
            numCount[i]--;
            answer[index] = nums[i];
            recursive(N,M,nums,numCount,index+1,answer);
            numCount[i]++;
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M,newN;
    int array[8];
    int count[8];
    int nums[8];
    int answer[8];
    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>array[i];


    sort(array,array+N);
    newN=1;
    nums[0]=array[0];
    count[0]=1;
    for(int i=1;i<N;i++)
    {
        if(array[i-1]!=array[i])
        {
            nums[newN]=array[i];
            count[newN]=1;
            newN++;
        }
        else
        {
            count[newN-1]++;
        }
    }
    
    recursive(newN,M,nums,count,0,answer);
    return 0;
}