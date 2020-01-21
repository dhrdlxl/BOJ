#include<iostream>
#include<algorithm>
using namespace std;
int nums[1000001];
int main(){
    int N;
    scanf("%d",&N);
    
    for(int i=2;i<N+1;i++)
    {
        nums[i]=nums[i-1]+1;
        if(i%2==0)nums[i]=min(nums[i],nums[i/2]+1);
        if(i%3==0)nums[i]=min(nums[i],nums[i/3]+1);
    }
    printf("%d",nums[N]);
    return 0;
}
