#include<iostream>
using namespace std;

bool nextPermutation(int* a,int n)
{
    int index=n-1;
    while(index>0 && a[index]<a[index-1])index--;
    if(index==0) return false;

    int targetIndex = n-1;
    while(a[index-1]>a[targetIndex])targetIndex--;

    swap(a[index-1],a[targetIndex]);
    int swapIndex = n-1;
    while(index<swapIndex)
    {
        swap(a[index++],a[swapIndex--]);
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
        array[i]=i+1;
    }
    
    do
    {
        for(int i=0;i<n;i++)
        {
            cout<<array[i]<<" ";
        }
        
        cout<<'\n';
    }while(nextPermutation(array,n));
    return 0;
}