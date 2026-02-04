#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    if(a[0]==a[n-1])cout<<-1;
    else 
    {   
        for(int i=0;i<n;i++)
        {
            if(a[i]==a[n-1]){cout<<i<<" "<<n-i<<"\n";break;}
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]!=a[n-1])cout<<a[i]<<" ";
        }cout<<"\n";
        for(int i=0;i<n;i++)
        {
            if(a[i]==a[n-1])cout<<a[i]<<" ";
        }
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