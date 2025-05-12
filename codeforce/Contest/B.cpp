#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
   int n,m,k;
   cin>>n>>m>>k;
   ll a[n],b[m];
   ll mxa=0,mxb=0,mna=INT_MAX,mnb=INT_MAX,sm=0;
   for(int i=0;i<n;i++){cin>>a[i];mxa=max(mxa,a[i]);mna=min(mna,a[i]);sm+=a[i];}
   for(int i=0;i<m;i++){cin>>b[i];mxb=max(mxb,b[i]);mnb=min(mnb,b[i]);}
   ll ans1,ans2;
   if(mna<mxb)
   {
     ans1=sm+mxb-mna;
     for(int i=0;i<n;i++)
     {
        if(a[i]==mna)
        {
            a[i]=mxb;
            break;
        }
     }
     for(int i=0;i<m;i++)
     {
        if(b[i]==mxb)
        {
            b[i]=mna;
            break;
        }
     }
   }
   else 
   {
    ans1=sm;
   }
   mxa=0,mxb=0,mna=INT_MAX,mnb=INT_MAX,sm=0;
   for(int i=0;i<n;i++){mxa=max(mxa,a[i]);mna=min(mna,a[i]);sm+=a[i];}
   for(int i=0;i<m;i++){mxb=max(mxb,b[i]);mnb=min(mnb,b[i]);}
   ans2=sm-mxa+mnb;
   if(k%2==1)cout<<ans1;
   else cout<<ans2;
   cout<<"\n";
   
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}