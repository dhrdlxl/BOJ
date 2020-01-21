#include<iostream>
#include<algorithm>
using namespace std;
int A[100000];
bool mysort(int i,int j)
{
    return i<j;
}
int main(){
    cin.sync_with_stdio(false);
    int N,M;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>A[i];
    
    sort(A,A+N,mysort);
    
    int target,front, back, privious_num;
    bool check;
    cin>>M;
    for(int i=0;i<M;i++)
    {
        cin>>target;
        check=false;
        front=0;
        back=N-1;
        privious_num=0;
        while(privious_num!=A[(front+back)/2])
        {
            privious_num = A[(front+back)/2];
            if(target>A[(front+back)/2]) front = (front+back)/2;
            else if(target<A[(front+back)/2]) back = (front+back)/2;
            else if(target==A[(front+back)/2])
            {
                check=true;
                break;
            }
        }
        if(check) cout<<1<<'\n';
        else if(A[N-1]==target)cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}