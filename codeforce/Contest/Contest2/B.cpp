#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
bool comp(pii a,pii b)
{
    return a.st<b.st;
}
void solve()
{
    ll n,p;
    cin>>n>>p;
    pii res[n];
    for(int i=0;i<n;i++)cin>>res[i].nd;
    for(int i=0;i<n;i++)cin>>res[i].st;
    sort(res,res+n);
    ll num=1;
    ll cost=p;
    for(int i=0;i<n;i++)
    { // cout<<cost;
       if(num==n)break;
       if(res[i].st<p)
       {
           if(res[i].nd+num>=n)
           {
             cost+=res[i].st*(n-num);
             break;
           }
           cost+=res[i].st*res[i].nd;
           num+=res[i].nd;
       }
       else 
       {
        cost+=p;
        num++;
       }
       
    }
    cout<<cost<<"\n";
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