#include<iostream>
using namespace std;

bool prePermutation(int* a,int n,int& ind)
{
    ind=-1;
    for(int i=n-1;i>0;i--)
    {
        if(a[i]<a[i-1])
        {
            ind = i-1;
            break;
        }
    }
    if(ind==-1) return false;

    int targetIndex=n-1;
    while(a[ind]<a[targetIndex])targetIndex--;
    
    swap(a[ind],a[targetIndex]);

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,index;
    int array[10000];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>array[i];

    if(prePermutation(&array[0],n,index))
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
    {
        cout<<"-1\n";
    }
    
    return 0;
}