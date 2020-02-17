#include<iostream>
using namespace std;
int Min =2e9;
int Max=-2e9;
int N;
int Nums[11];
void calculate(int count,int ops[4],int result)
{
    for(int i=0;i<4;i++)//실패
    {
        if(ops[i]<0) return;   
    }
    
    if(count==N)
    {
        if(Min>result) Min = result;
        if(Max<result) Max = result;
        return;//성공
    } 

    ops[0]--;
    calculate(count+1,ops,result+Nums[count]);
    ops[0]++;
    ops[1]--;
    calculate(count+1,ops,result-Nums[count]);
    ops[1]++;
    ops[2]--;
    calculate(count+1,ops,result*Nums[count]);
    ops[2]++;
    ops[3]--;
    calculate(count+1,ops,result/Nums[count]);
    ops[3]++;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int operators[4];
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>Nums[i];

    for(int i=0;i<4;i++)
        cin>>operators[i];
    
    calculate(1,operators,Nums[0]);
    cout<<Max<<'\n'<<Min;
    return 0;
}