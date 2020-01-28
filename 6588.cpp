#include<iostream>
using namespace std;
const int MAX=1000000;
int prime[MAX/2];
bool check[MAX+1];
int primeCount;
void eratosthenes(){
    for(int i=2;i<=MAX;i++){
        if(check[i]==false){
            prime[primeCount++]=i;
            for(int j=i+i;j<=MAX;j+=i){
                check[j]=true;
            }
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    
    eratosthenes();
    
    while(1){
        cin>>n;
        if(n==0) break;
        bool Goldbach=false;
        for(int i=1;i<primeCount;i++)
        {
            if(n<prime[i])break;
            if(check[n-prime[i]]==false)
            {
                Goldbach=true;
                cout<<n<<" = "<<prime[i]<<" + "<<n-prime[i]<<'\n';
                break;
            }
        }
        if(!Goldbach)
            cout<<"Goldbach's conjecture is wrong."<<'n';
    }
    return 0;
}