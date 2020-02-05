#include<iostream>
using namespace std;


bool nextPermutation(int* a,int n, int& index)
{
    index=-1;
    for(int i=n-1;i>0;i--)
    {
        if(a[i]>a[i-1])
        {
            index=i-1;
            break;
        }
    }

    if(index==-1) 
        return false;

    int changeIndex=n-1;
    while(a[index]>a[changeIndex]) changeIndex--;

    int temp=0;
    temp = a[index];
    a[index] = a[changeIndex];
    a[changeIndex] = temp;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int array[10000];
    int index=-1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    
    if(nextPermutation(array,n,index))
    {
        for(int i=0;i<=index;i++)
        {
            cout<<array[i]<<" ";
        }
        for(int i=n-1;i>index;i--)
        {
            cout<<array[i]<<" ";
        }
    }
    else
        cout<<index;
        
    return 0;
}