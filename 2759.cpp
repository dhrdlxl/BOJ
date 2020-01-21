#include<iostream>
#include<algorithm>
using namespace std;
int nums[1001];
bool mysort(int i,int j){return i<j;}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&nums[i]);
    }
    sort(nums,nums+N,mysort);
    for(int i=0;i<N;i++)
    {
        printf("%d\n",nums[i]);
    }
    return 0;
}