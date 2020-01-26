#include<iostream>
#include<stack>
using namespace std;
int A[1000000], count[1000001], NFG[1000000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    stack<int> index;
    
    int N;
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
        count[A[i]]++;
    }
    for(int i=0;i<N;i++)
    {
        while(!index.empty() && count[A[i]]>count[A[index.top()]])
        {
            NFG[index.top()]=A[i];
            index.pop();
        } 
        index.push(i);
    }
    while(!index.empty())
    {
        NFG[index.top()]=-1;
        index.pop();
    }
    for(int i=0;i<N;i++)
        cout<<NFG[i]<<" ";
    
    
    return 0;
}