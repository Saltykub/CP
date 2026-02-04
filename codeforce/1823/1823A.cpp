#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
int precom[120];
void solve()
{ 
   int n,k;
   cin>>n>>k;
   for(int i=0;i<=n;i++)
   {
     if(precom[i]+precom[n-i]==k)
     {
        cout<<"YES"<<"\n";
        for(int j=0;j<i;j++)cout<<1<<" ";
        for(int j=0;j<n-i;j++)cout<<-1<<" ";
        cout << "\n";
        return;
     }
   }
   cout<<"NO\n";
}
int main()
{ 
   int t;
   cin>>t;
   for(int i=0;i<120;i++){
     precom[i]=(i*(i-1))/2;
   }
   while(t--){
     solve();
   }
}