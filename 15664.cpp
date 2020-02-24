#include<iostream>
#include<algorithm>
using namespace std;

void recursive(int N,int M,int* nums,int* countNums,int start,int count,int* answer)
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

    for(int i=start;i<N;i++)
    {
        if(countNums[i]>0)
        {
            answer[count]=nums[i];
            countNums[i]--;
            recursive(N,M,nums,countNums,i,count+1,answer);
            countNums[i]++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M,newN;
    int nums[8];
    int deDuplication[8];
    int countNums[8];
    int answer[8];

    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>nums[i];
    sort(nums,nums+N);

    newN=1;
    deDuplication[0]=nums[0];
    countNums[0]=1;
    for(int i=1;i<N;i++)
    {
        if(nums[i]!=nums[i-1])
        {
            deDuplication[newN]=nums[i];
            countNums[newN]=1;
            newN++;
        }
        else
        {
            countNums[newN-1]++;
        }
    }

    recursive(newN,M,deDuplication,countNums,0,0,answer);
    return 0;
}