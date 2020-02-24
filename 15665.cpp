#include<iostream>
#include<algorithm>
using namespace std;

void recursive(int N,int M,int* nums,int count,int* answer)
{
    if(M==count)
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
        answer[count]=nums[i];
        recursive(N,M,nums,count+1,answer);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M,newN;
    int nums[8];
    int deDuplication[8];
    int answer[8];

    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>nums[i];
    sort(nums,nums+N);

    newN=1;
    deDuplication[0]=nums[0];
    for(int i=1;i<N;i++)
    {
        if(nums[i]!=nums[i-1])
        {
            deDuplication[newN]=nums[i];
            newN++;
        }
    }

    recursive(newN,M,deDuplication,0,answer);
    return 0;
}