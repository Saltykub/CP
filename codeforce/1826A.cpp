#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
int check[110];
void solve()
{ 
   int n,nn;
   cin>>n;
   nn=n;
   bool can=false;
   for(int i=0;i<110;i++)check[i]=0;
   while(nn--)
   {int x;
    cin>>x;
    check[x]++;
   }
   for(int i=0;i<=n;i++)
   {
    if(check[i]>=n-i)
    {
        cout<<n-i;
        can=true;
        break;
    }
   }
   if(can==false)cout<<-1;
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