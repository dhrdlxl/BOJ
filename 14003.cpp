#include<iostream>
#include<stack>
using namespace std;

struct pos{
    int ind;
    int val;
};
int arr[1000000];
int lis[1000000];
pos index[1000000];

int BinearySearch(int begin, int end,int x)
{

    int mid;
    while(begin!=end)
    {
        mid = (begin+end)/2;
        if(lis[mid]<x)
        {
            begin=mid+1;
        }
        else if(lis[mid]>=x)
        {
            end = mid;
        }
    }
    return end;
}

//Bineary Search를 이용한 O(nlogn) 방법
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    int j=0;
    
    cin>>N;

    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        if(arr[i]>lis[j])
        {
            if(i!=0)
                j++;
            lis[j]=arr[i];
            index[i].ind=j;
            index[i].val=arr[i];
        }
        else if(arr[i]<=lis[j])
        {
            int searchIndex = BinearySearch(0,j,arr[i]);
            lis[searchIndex] = arr[i];
            index[i].ind=searchIndex;
            index[i].val=arr[i];
        }
    }
    
    cout<<j+1<<'\n';
    stack<int> st;
    for(int i=N-1;i>=0;i--)
    {
        if(index[i].ind==j)
        {
            st.push(index[i].val);
            j--;
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<' ';
        st.pop();
    }

    return 0;
}