#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> trustMap(10000);
bool mask[10001];

int main(){
    int N,M;
    cin>>N>>M;
    
    
    int num1,num2;
    for(int i=0; i<M;i++)
    {
        cin>>num1>>num2;
        trustMap[num2].push_back(num1);
    }
    
    //bfs
    
    for(int i=0;i<10001;i++)mask[i]=true;
    
    int maxCount=0;//최대 Count 수
    queue<int> answerQueue;
    
    queue<int> bfsQueue;
    for(int i=1;i<=N;i++)
    {
        int count=1;
        bfsQueue.push(i);
        while(bfsQueue.size()>0)
        {
            int node = bfsQueue.front();
            bfsQueue.pop();
            mask[node] = false;
            
            //내부 로직
            for(int j=0; j<trustMap[node].size(); j++){
                if(mask[trustMap[node][j]]){
                    bfsQueue.push(trustMap[node][j]);
                    mask[trustMap[node][j]]=false;
                    count++;
                }
            }
        }
        if(maxCount<count)
        {
            while(answerQueue.size()>0)answerQueue.pop();
            answerQueue.push(i);
            maxCount = count;
        }
        else if(maxCount==count)answerQueue.push(i);
        for(int j=0;j<10001;j++)mask[j]=true;
    }
    
    while(answerQueue.size()>0)
    {
        cout<<answerQueue.front()<<" ";
        answerQueue.pop();
    }
    
    
    return 0;
}