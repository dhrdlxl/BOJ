#include<iostream>
#include<stack>
using namespace std;
int NGE[1000000],A[1000000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    stack<int> index;
    
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>A[i];
    for(int i=0;i<N;i++)
    {
        while(!index.empty() && A[index.top()]<A[i] )
        {
            NGE[index.top()]=A[i];
            index.pop();
        }
        index.push(i);
    }

    while(!index.empty())
    {
        NGE[index.top()]=-1;
        index.pop();
    }    
    for(int i=0;i<N;i++)
    {
        cout<<NGE[i]<<" ";
    }
    
    return 0;
}