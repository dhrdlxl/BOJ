#include<iostream>
#include<algorithm>
using namespace std;

bool nextPermutation(int* a,int n)
{
    int index=n-1;

    while(index>0&&a[index]<=a[index-1])index--;//같은 값이 존재 할 수 있으므로 = 사용
    if(index==0) return false;

    int targetIndex=n-1;
    while(a[index-1]>=a[targetIndex])targetIndex--;//같은 값이 존재 할 수 있으므로 = 사용

    swap(a[index-1],a[targetIndex]);
    
    targetIndex = n-1;
    while(index<targetIndex)
    {
        swap(a[index++],a[targetIndex--]);
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int array[8];
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }

    sort(array,array+n);

    int answer=0;
    do{
        int sum=0;
        int abs;
        for(int i=0;i<n-1;i++)
        {
            abs = array[i]-array[i+1];
            if(abs<0)abs*=-1;
            sum+=abs;
        }
        if(answer<sum)answer=sum;
    }while(nextPermutation(array,n));

    cout<<answer;

    return 0;
}