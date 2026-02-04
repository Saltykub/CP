#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=125;
int a[N];
void solve()
{ 
   int n,half,one=0,negone=0;
   cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<=n;i++)
   {
        if(a[i]==1)one++;
        else negone++;
   }
   if(one>=negone)
   {
      if(negone%2==0)cout<<0;
      else cout<<1;
   }
   else 
   {  
      half=n/2;
      int ans=negone-half;
      if(half%2==1)ans++;
      cout<<ans;
   }
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