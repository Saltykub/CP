#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
   int n,m;
   cin>>n>>m;
   if(n<m)
   {
    (m==1) ? cout<<0<<"\n" : cout<<min(m,n+1)<<"\n";
   for(int i=0;i<n;i++)
   {
        for(int j=i;j<m;j++)cout<<j<<" ";
        for(int j=0;j<i;j++)cout<<j<<" ";
        cout<<"\n";
   }
   }
   else 
   {
    // (m==1) ? cout<<0<<"\n" : cout<<m<<"\n";
    cout << (m == 1 ? 0 : m) << "\n";
    for(int i=0;i<m-1;i++)
   {    
        for(int j=i;j<m;j++)cout<<j<<" ";
        for(int j=0;j<i;j++)cout<<j<<" ";
        cout<<"\n";
   }
   for(int i=m-1;i<n;i++)
   {
    for(int j=0;j<m;j++)cout<<j<<" ";
    cout<<"\n";
   }
   }
}
int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        
        solve();
    }
}