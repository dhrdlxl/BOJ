#include <iostream>
#include <algorithm>
using namespace std;

int sequence1[1050000];
int sequence2[1050000];
int minf(int a,int b)
{
  return a<b;
}
int maxf(int a,int b)
{
  return a>b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N,S;
  int div1[20];
  int div2[20];
  cin>>N>>S;

  int div1Size = N/2;
  int div2Size = N-N/2;
  for(int i=0;i<div1Size;i++)
  {
    cin>>div1[i];
  }
  for(int i=0;i<div2Size;i++)
  {
    cin>>div2[i];
  }
  

  //div1이 만들 수 있는 모든 부분수열의 합
  for(int i=0;i<(1<<div1Size);i++)
  {
    int sum=0;
    for(int j=0;j<div1Size;j++)
    {
      if((i&(1<<j)) > 0)
        sum+=div1[j];
    }
    sequence1[i]=sum;
  }
  
  //div2가 만들 수 있는 모든 부분수열의 합
  for(int i=0;i<(1<<div2Size);i++)
  {
    int sum=0;
    for(int j=0;j<div2Size;j++)
    {
      if((i&(1<<j)) > 0)
        sum+=div2[j];
    }
    sequence2[i]=sum;
  }
  
  sort(sequence1,sequence1+(1<<div1Size),minf);//오름차순
  sort(sequence2,sequence2+(1<<div2Size),maxf);//내림차순

  int i=0,j=0;
  int sum=0;
  long long int answer=0;
  
  while(i<(1<<div1Size) && j<(1<<div2Size))
  {
      sum=sequence1[i]+sequence2[j];
      if(sum<S) i++;
      else if(sum>S) j++;
      else if(sum==S)
      {
        long long int count1=1,count2=1;
        for(i=i+1;i<(1<<div1Size);i++)
        {
          if(sequence1[i-1]==sequence1[i]) count1++;
          else break;
        }
        for(j=j+1;j<(1<<div2Size);j++)
        {
          if(sequence2[j-1]==sequence2[j]) count2++;
          else break;
        }
        answer+=count1*count2;
      } 
  }
  if(S==0)answer--;
  cout<<answer;
  return 0;
}