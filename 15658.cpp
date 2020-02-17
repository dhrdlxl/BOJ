#include<iostream>
#include<vector>
using namespace std;

pair<int, int> calculate(int* nums,int index,int N,int Ops[4],int result)
{
    if(index==N)
    {
        return make_pair(result,result);
    }
    vector<pair<int,int>> correctCandidate;
    if(Ops[0]>0)
    {
        Ops[0]--;
        correctCandidate.push_back(calculate(nums,index+1,N,Ops,result+nums[index]));
        Ops[0]++;
    }
    if(Ops[1]>0)
    {
        Ops[1]--;
        correctCandidate.push_back(calculate(nums,index+1,N,Ops,result-nums[index]));
        Ops[1]++;
    }
    if(Ops[2]>0)
    {
        Ops[2]--;
        correctCandidate.push_back(calculate(nums,index+1,N,Ops,result*nums[index]));
        Ops[2]++;
    }
    if(Ops[3]>0)
    {
        Ops[3]--;
        correctCandidate.push_back(calculate(nums,index+1,N,Ops,result/nums[index]));
        Ops[3]++;
    }
    pair<int,int> answer = correctCandidate[0];
    for(pair<int,int> x : correctCandidate)
    {
        if(answer.first<x.first)answer.first = x.first;
        if(answer.second>x.second)answer.second = x.second;
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int nArray[11];
    int Operators[4];
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>nArray[i];
    for(int i=0;i<4;i++)
        cin>>Operators[i];

    pair<int,int> answer;
    answer=calculate(nArray,1,N,Operators,nArray[0]);
    
    cout<<answer.first<<'\n'<<answer.second;
    return 0;
}