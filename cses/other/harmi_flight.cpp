#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[(1<<20)+10]; 
vector<int> adj[25];
int main(){
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
   }
   dp[1]=1;
   for(int i=1;i<(1<<n);i++){
    
   }
}