#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool nextPermutation(vector<int>& a,int n)
{
    int index=n-1;
    while(index>0 && a[index-1]>=a[index]) index--;
    if(index==0) return false;

    int targetIndex=n-1;
    while(a[index-1]>=a[targetIndex])targetIndex--;

    swap(a[index-1],a[targetIndex]);

    targetIndex=n-1;
    while(index<targetIndex)
    {
        swap(a[index++],a[targetIndex--]);
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int nArray[11];
    int Operator[4];

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>nArray[i];
    }

    vector<int> vec;
    for(int i=0;i<4;i++)
    {
        cin>>Operator[i];
        for(int j=0;j<Operator[i];j++)
        {
            vec.push_back(i);
        }
    }
    
    int max= -2e9;
    int min= 2e9;
    do{
        int sum=nArray[0];
        for(int i=0;i<n-1;i++)
        {
            if(vec[i]==0)// +
            {
                sum+=nArray[i+1];
            }
            else if(vec[i]==1)// -
            {
                sum-=nArray[i+1];
            }
            else if(vec[i]==2)// x
            {
                sum*=nArray[i+1];
            }
            else if(vec[i]==3)// /
            {
                sum/=nArray[i+1];
            }
        }
        if(sum>max)max=sum;
        if(sum<min)min=sum;
    }while(nextPermutation(vec,n-1));

    cout<<max<<'\n'<<min<<'\n';
    return 0;
}