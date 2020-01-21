#include<iostream>

using namespace std;

int main(){
    int N,M;
    cin.sync_with_stdio(false);
    cin>>N;
    M=N;
    int sum=0;
    int num=0;
    int count=0;
    do{
            count++;
            M/=10;
        }while(M>0);
    for(int i=N-9*count;i<N+1;i++)
    {
        num = i; 
        do{
            sum=sum+num%10;
            num/=10;
        }while(num>0);
        if(i+sum ==N){
            cout<<i;
            return 0;
        }
        sum=0;
    }
    cout<<0;
    return 0;
}