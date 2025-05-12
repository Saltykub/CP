#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[(1<<20)+10][2];  // min wa
int main(){
    ll n,x;
    cin>>n>>x;
    ll arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<(1<<n);i++)dp[i][0]=dp[i][1]=1e9+2;
    for(int i=0;i<n;i++){dp[(1<<i)][0]=1;dp[(1<<i)][1]=arr[i];} 
    for(int i=0;i<(1<<n);i++){
        
        for(int j=0;j<n;j++)
        {  
           if(i&(1<<j)==0)continue;
           int prev=(i^(1<<j));
           if(arr[j]+dp[prev][1]<=x)
           {
                if(dp[prev][0]<=dp[i][0]){
                    dp[i][0]=dp[prev][0];
                    dp[i][1]=min(dp[prev][1]+arr[j],dp[i][1]);
                }
           }
           else {
                if(dp[i][0]>=dp[prev][0]+1)
                {
                    dp[i][0]=dp[prev][0]+1;
                    dp[i][1]=min(dp[i][1],arr[j]);
                }
           }
        }
        
    }
    cout<<dp[(1<<n)-1][0]<<"\n";
   
}