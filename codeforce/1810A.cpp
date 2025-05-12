#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
   bool can=false;
   int n;cin>>n;
   for(int i=1;i<=n;i++)
   {
    int x;
    cin>>x;
    if(x<=i)can=true;
   }
   can ? cout<<"yes":cout<<"no";
   cout<<"\n";
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